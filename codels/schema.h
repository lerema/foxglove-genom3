#ifndef CODELS_SCHEMA_H_
#define CODELS_SCHEMA_H_

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

std::string executeCommand(const std::string &command)
{
    std::ostringstream output;
    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe)
    {
        throw std::runtime_error("popen() failed.");
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        output << buffer;
    }

    int status = pclose(pipe);
    if (status != 0)
    {
        throw std::runtime_error("Command execution failed.");
    }

    return output.str().substr(0, output.str().size() - 1);
}

enum class SchemaDefinition
{
    SceneUpdate,
    RawImage,

};

struct Schema
{
    std::string getSchemaPath()
    {
        return schema_path;
    }

    std::string getSchemaDefinitionPath(SchemaDefinition schema_definition)
    {
        switch (schema_definition)
        {
        case SchemaDefinition::SceneUpdate:
            return schema_path + "/SceneUpdate.bfbs";
        case SchemaDefinition::RawImage:
            return schema_path + "/RawImage.bfbs";
        default:
            throw std::runtime_error("Schema definition not found.");
        }
    }

private:
    const char *pkg_config_cmd = "pkg-config FoxgloveStudio-genom3 --variable=datarootdir";
    const std::string pkg_config_path = executeCommand(pkg_config_cmd);
    const std::string schema_path = pkg_config_path + "/foxglovestudio-genom3/flatbuffers/schema";
};
#endif // CODELS_SCHEMA_H_
