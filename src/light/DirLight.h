// Copyright (c) 2016-2018 Dalton Hildreth
// This file is under the MIT license. See the LICENSE file for details.
#ifndef DIR_LIGHT_H
#define DIR_LIGHT_H

#include "Light.h"

class DirLight : public Light {
public:
    DirLight();

    virtual void pass_to(Shader& shader, const std::string& id);

    glm::vec3 dir();
    void dir(glm::vec3);
private:
    glm::vec3 _dir;
};

#endif//DIR_LIGHT_H
