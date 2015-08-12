#ifndef TARGETOPTIMIZATION_H
#define TARGETOPTIMIZATION_H

#include "ceres/ceres.h"

#include "glog/logging.h"
#include "SurfaceModel.h"
#include "utils.h"

class TargetOptimization
{
    vector<glm::vec3> computeNormals;
    Model* model;

public:
    TargetOptimization();
    ~TargetOptimization();
    void runOptimization(Model* m);
    void runCeresTest();
    void optimize();
    bool converged();
};

#endif // TARGETOPTIMIZATION_H
