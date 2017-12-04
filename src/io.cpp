#include "io.h"
#include <fstream>
#include <iostream>
#include <stb_image.h>
#include <optional>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/norm.hpp>
#undef GLM_ENABLE_EXPERIMENTAL

using namespace std;
#ifndef WIN32
using namespace std::experimental;
#endif

optional<const string> read_file(const string path) {
    ifstream file(path, ios::in | ios::binary);
    if (!file) {
        cerr << "gg! Failed to open file " << path << "\n";
        return nullopt;
    }

    file.seekg(0, ios::end);
    string content(static_cast<size_t>(file.tellg()), '\0');
    file.seekg(0, ios::beg);
    file.read(&content[0], static_cast<long int>(content.size()));
    if (!file) {
        cerr << "gg! Failed to read entire file " << path << "\n";
        return nullopt; 
    }

    return content;
}

optional<Image> read_image(const string path) {
    Image i;
    i.bytes = stbi_load(path.c_str(), &i.width, &i.height, &i.channels, 0);
    if (i.bytes) {
        return i;
    } else {
        return nullopt;
    }
}
