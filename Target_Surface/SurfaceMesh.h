#ifndef SURFACEMESH_H
#define SURFACEMESH_H
//#pragma comment(lib, \"assimp.lib\")

#include "global.h"
#include <math.h>
#include <vector>
#include <string>
/*Assimp Open Asset Import Librairy*/
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing fla
#include "utils.h"
#include "glm/gtx/vector_angle.hpp"

using namespace std;

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    GLuint id;
    string type;
};


class Mesh {
public:
        /*  Mesh Data  */
        vector<Vertex> vertices;
        vector<glm::uvec3> indices;
        vector<glm::uvec3> edgeIndices;
        vector<vector<uint> > edgeAdjacentFaces;
        vector<vector<uint> > adjacentFaces;
        vector<Texture> textures;
        int nbMeshLayout;
        float maxX, maxY, maxZ;
       //int nbTriangle;
        /*  Render data  */
        GLuint VAO, VBO, EBO;
        /*  Functions  */
        vector<Vertex*> allVertices;
        vector<Vertex*> faceVertices;
        vector<Vertex*> faceVerticesEdge;

        /*different mappings*/
        vector<int> edgeToNoEdgeMapping;
        vector<int> noEdgeToEdgeMapping;
        vector<int> allToEdgeMapping;
        vector<int> edgeToAllMapping;
        vector<int> indicesToEdgesIndices;
        vector<int> faceEdgeIndicesToIndices;

        Mesh(vector<Vertex> vertices, vector<Texture> textures, vector<glm::uvec3> indices, float max_X, float max_Y, float max_Z/*, vector<int> edgeIndicesToIndices*/);
        Mesh(){}
        //void Draw(Shader shader);
        void setUpMesh(int nbvertices);
        float vectorNorm(Vertex v0, Vertex v1);
        vector<int> longerSegment(Vertex v0, Vertex v1, Vertex v2, int first);
        bool adjacent(vector<Vertex> vec1, vector<Vertex> vec2);
        bool equal(vector<Vertex> vec1, vector<Vertex> vec2);
        bool compareArea(vector<Vertex> vec1, vector<Vertex> vec2); //return true if vec2 bigger or equal than vec1
        void create_indices();
        void shrink_vertices();
        void rescale(float oldScale, float newScale);
        void calcMax();
        void expandVertices(std::vector<Vertex>& outVertices);
        void calculateVertexNormals();
        void calculateVertexNormal(std::vector<glm::vec3> & faceNormals, uint vertexIndex);
        void getAdjacentFacesVector();
        void updateNormal(Vertex* v);
        void createEdgeIndices();
        void calcEdgeAdjacentFaces();
        void calculateFaceNormals(std::vector<glm::vec3>& normals);
        void calculateFaceNormal(glm::vec3 & normal, uint faceIndex);
        bool isEdge(Vertex* v); //return true if the vertex is an edge
        int getIndex(Vertex* v);
        int getIndex(int v);
        int getEdgeIndex(int i);
        int getIndexTargetSurface(Vertex* v);
        std::vector<int> createNoEdgeToEdgeMapping();
        std::vector<int> createEdgeToNoEdgeMapping();
        vector<int> getNeighborsIndex(Vertex *v); //return the index in faceVertices of the vertex of faceVertices with the index as parameter
        vector<int> getNeighborsIndex(int v, int indexTargetSurface); //v index in faceVertices
        vector<int> getClosestNeighbors(Vertex* v);
        //void shrink_vertices_camille(); //reimplementation
        vector<Vertex*> selectVerticesMeshFaceNoEdge(); //select the vertex on the face the furthest on x axis
        vector<Vertex*> selectVerticesMeshFaceEdge(); //select the vertex on the face the furthest on x axis
        void setVertices();
        void exportVertices(const QString& filename, float scaling);
        float getMaxX(){return maxX;};
        vector<int> insertSorted(vector<int> vec, int in, Vertex* v2);
};

class TargetSurfaceMesh : public Mesh {
    double m_dx; //corresponding to the one in the scene
    double m_dy;

public:
    TargetSurfaceMesh(double dx, double dy){}
    TargetSurfaceMesh(){}
    ~TargetSurfaceMesh(){}
    double get_dx() const { return m_dx; }
    double get_dy() const { return m_dy; }
};

#endif // SURFACEMESH_H
