#ifndef TASK_H
#define TASK_H

#include <string>
#include "external/crow_all.h"

struct Task
{
    int id;
    std::string name;
    int priority;

    crow::json::wvalue to_json() const
    {
        crow::json::wvalue json;
        json["id"] = id;
        json["name"] = name;
        json["priority"] = priority;
        return json;
    }
};

#endif // TASK_H
