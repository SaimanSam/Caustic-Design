#ifndef GLOBAL_H
#define GLOBAL_H
#define GL_GLEXT_PROTOTYPES
#include "GL/glew.h"
#include "GL/glext.h"

#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "GL/freeglut.h"
#include "GL/glext.h"
#define GLM_PRECISION_HIGHP_DOUBLE
#include "glm/glm.hpp"

#include <QGLWidget>
#include <QGLFunctions>

#include <glog/logging.h>

#include <iostream>
#include<numeric>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#define MESH_AMOUNT 50 //amount of
#define CAUSTIC_DOMAIN 0.5

/*Physical model*/
#define MATERIAL_REFRACTIV_INDEX 1.49//value for acrylic used in the paper to do test experimently
#define NORMALS 961 //size of vertex in the front face 961 without the edges 1089 with edges


/**/
#define CONVERGENCE_LIMIT 0.0001
#define AIR_REFRACTIV_INDEX 1
#define EBAR_DETH 100
#define EINT_WEIGHT 1.0
#define EBAR_WEIGHT 1.0
#define EDIR_WEIGHT 1e-4
#define EREG_WEIGHT 1e-5

typedef float (array)[NORMALS];




#endif // GLOBAL_H
