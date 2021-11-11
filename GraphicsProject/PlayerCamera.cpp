#include "PlayerCamera.h"
#include "GLFW/glfw3.h"

//For zooming in & out
void scroll_callback(GLFWwindow* window, double xPos, double yPos);
float mouseWheel;

void PlayerCamera::onUpdate(float deltaTime)
{
    GLFWwindow* window = glfwGetCurrentContext();

    int keyForward = GLFW_KEY_W;
    int keyBack = GLFW_KEY_S;
    int keyLeft = GLFW_KEY_A;
    int keyRight = GLFW_KEY_D;
    int keyUp = GLFW_KEY_E;
    int keyDown = GLFW_KEY_Q;
    int keySprint = GLFW_KEY_LEFT_SHIFT;
    int keySlow = GLFW_KEY_LEFT_CONTROL;

    //Get the direction vectors
    glm::vec3 right = getTransform()->getRight();
    glm::vec3 up = getTransform()->getUp();
    glm::vec3 forward = getTransform()->getForward();
    float sprintSpeed = m_moveSpeed;

    //Checks if sprinting
    if (glfwGetKey(window, keySprint))
        sprintSpeed *= 2;

    if (glfwGetKey(window, keySlow))
        sprintSpeed /= 2;

    //Check input
    //Move forward
    if (glfwGetKey(window, keyForward))
        getTransform()->translate(forward * sprintSpeed * (float)deltaTime);

    //Move back
    if (glfwGetKey(window, keyBack))
        getTransform()->translate(-forward * sprintSpeed * (float)deltaTime);

    //Move left
    if (glfwGetKey(window, keyLeft))
        getTransform()->translate(-right * sprintSpeed * (float)deltaTime);

    //Move right
    if (glfwGetKey(window, keyRight))
        getTransform()->translate(right * sprintSpeed * (float)deltaTime);

    //Move up
    if (glfwGetKey(window, keyUp))
        getTransform()->translate(up * sprintSpeed * (float)deltaTime);

    //Move down
    if (glfwGetKey(window, keyDown))
        getTransform()->translate(-up * sprintSpeed * (float)deltaTime);

    //Zoom in & out
    glfwSetScrollCallback(window, scroll_callback);
    if (mouseWheel != 0)
    {
        if (getFieldOfView() >= 1.0f && getFieldOfView() <= 45.0f)
            setFieldOfView(getFieldOfView() - mouseWheel);
        if (getFieldOfView() < 1.0f)
            setFieldOfView(1.0f);
        if (getFieldOfView() > 45.0f)
            setFieldOfView(45.0f);

        mouseWheel = 0;
    }

    //Get current mouse coordinates
    glfwGetCursorPos(window, &m_currentMouseX, &m_currentMouseY);

    //Turn the camera based on the change in mouse position (delta mouse)
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2)) {
        float pitch = m_lookSpeed * (m_currentMouseY - m_previousMouseY);
        float yaw = m_lookSpeed * (m_currentMouseX - m_previousMouseX);

        getTransform()->rotate(-pitch, yaw, 0.0f);

        if (getTransform()->getRotation().x >= 90)
            getTransform()->rotate(pitch,0,0);
        if (getTransform()->getRotation().x <= -90)
            getTransform()->rotate(pitch,0,0);
    }

    //Store previous mouse coordinates
    m_previousMouseX = m_currentMouseX;
    m_previousMouseY = m_currentMouseY;
}

//Gives back the y value of the scrollWheel
void scroll_callback(GLFWwindow* window, double xPos, double yPos)
{
    mouseWheel = yPos;
}
