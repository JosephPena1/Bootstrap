#version 410

in vec4 fPosition;
in vec4 fNormal;
in vec4 fColor;
in vec2 fTexCoord;

uniform vec3 kAmbient;
uniform vec3 kDiffuse;
uniform vec3 kSpecular;
uniform float kSpecularPower;

//Light 0
uniform vec3 iDirection0;
uniform vec3 iAmbient0;
uniform vec3 iDiffuse0;
uniform vec3 iSpecular0;

//Light 1
uniform vec3 iDirection1;
uniform vec3 iAmbient1;
uniform vec3 iDiffuse1;
uniform vec3 iSpecular1;

//Light 2
uniform vec3 iDirection2;
uniform vec3 iAmbient2;
uniform vec3 iDiffuse2;
uniform vec3 iSpecular2;

uniform vec3 cameraPosition;
uniform sampler2D diffuseTexture;

out vec4 pColor;

void main() {
	vec3 kNormal = normalize(fNormal.xyz);
	vec3 iNormal0 = normalize(iDirection0);
	vec3 iNormal1 = normalize(iDirection1);
	vec3 iNormal2 = normalize(iDirection2);

	//Light [0]
	//Calculate ambient color
	vec3 ambientColor0 = (fColor.xyz + kAmbient) * iAmbient0;

	//Calculate diffuse color
	float lambertTerm0 = dot(kNormal, -iNormal0);
	lambertTerm0 = max(0.0f, min(1.0f, lambertTerm0));
	vec3 diffuseColor0 = (fColor.xyz + kDiffuse) * iDiffuse0 * lambertTerm0;

	//Calculate specular color
	vec3 surfaceToView0 = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal0 = reflect(iNormal0, kNormal);
	float specularTerm0 = dot(surfaceToView0, reflectionNormal0);
	specularTerm0 = max(0.0f, specularTerm0);
	specularTerm0 = pow(specularTerm0, kSpecularPower);
	vec3 specularColor0 = (fColor.xyz + kSpecular) * iSpecular0 * specularTerm0;

	vec4 color0 = vec4(ambientColor0 + diffuseColor0 + specularColor0, 1.0f);

	//Light [1]
	//Calculate ambient color
	vec3 ambientColor1 = (fColor.xyz + kAmbient) * iAmbient1;

	//Calculate diffuse color
	float lambertTerm1 = dot(kNormal, -iNormal1);
	lambertTerm1 = max(0.0f, min(1.0f, lambertTerm1));
	vec3 diffuseColor1 = (fColor.xyz + kDiffuse) * iDiffuse1 * lambertTerm1;

	//Calculate specular color
	vec3 surfaceToView1 = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal1 = reflect(iNormal1, kNormal);
	float specularTerm1 = dot(surfaceToView1, reflectionNormal1);
	specularTerm1 = max(0.0f, specularTerm1);
	specularTerm1 = pow(specularTerm1, kSpecularPower);
	vec3 specularColor1 = (fColor.xyz + kSpecular) * iSpecular1 * specularTerm1;

	vec4 color1 = vec4(ambientColor1 + diffuseColor1 + specularColor1, 1.0f);

	//Light [2]
	//Calculate ambient color
	vec3 ambientColor2 = (fColor.xyz + kAmbient) * iAmbient2;

	//Calculate diffuse color
	float lambertTerm2 = dot(kNormal, -iNormal2);
	lambertTerm2 = max(0.0f, min(1.0f, lambertTerm2));
	vec3 diffuseColor2 = (fColor.xyz + kDiffuse) * iDiffuse2 * lambertTerm2;

	//Calculate specular color
	vec3 surfaceToView2 = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal2 = reflect(iNormal2, kNormal);
	float specularTerm2 = dot(surfaceToView2, reflectionNormal2);
	specularTerm2 = max(0.0f, specularTerm2);
	specularTerm2 = pow(specularTerm2, kSpecularPower);
	vec3 specularColor2 = (fColor.xyz + kSpecular) * iSpecular2 * specularTerm2;

	vec4 color2 = vec4(ambientColor2 + diffuseColor2 + specularColor2, 1.0f);

	vec4 texColor = fColor * texture(diffuseTexture, fTexCoord);

	//Add the color from every light
	pColor = (color0 + color1 + color2) + texColor;
}
