#include "Model.h"
#include <iostream>

using namespace brd;
using namespace std;

Model::Model()
{
    components.resize(ComponentType_COUNT);
    for(size_t i=0; i<components.size(); i++)
        components[i] = nullptr;

    addComponent(new Transform());
}

Model::~Model()
{
    for(auto component : components)
        delete component;
}

Model* Model::Create(const char* _name)
{
	Model* model = new Model();
    model->name      = _name;
	return model;
}

