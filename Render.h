#ifndef _RENDER_H_
#define _RENDER_H_


#include <vector>

#include "Algebra.h"
#include "SceneData.h"
#include "SceneParser.h"
#include "Shape.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Sphere.h"
#include "Steinmetz.h"

using namespace std;


class SceneRenderer {
private:
    vector<Matrix> transforms;
    vector<Shape*> objs;

    inline Matrix getMatrixFromTransform(SceneTransformation *trans) {
        switch (trans->type) {
            case TRANSFORMATION_TRANSLATE:
                return trans_mat(trans->translate);
            case TRANSFORMATION_SCALE:
                return scale_mat(trans->scale);
            case TRANSFORMATION_ROTATE:
                return rot_mat(trans->rotate, trans->angle);
            case TRANSFORMATION_MATRIX:
                return trans->matrix;
        }
    }

    // remember to delete shape in SceneRenderer destructor
    inline Shape *getShapeFromPrimitive(ScenePrimitive *prim) {
        switch (prim->type) {
            case SHAPE_CUBE:
                return new Cube();
            case SHAPE_CYLINDER:
                return new Cylinder();
            case SHAPE_CONE:
                return new Cone();
            case SHAPE_SPHERE:
                return new Sphere();
            case SHAPE_SPECIAL1:
                return new Steinmetz();
            default: // special2, special3, mesh (for now)
                return new Cube();
        }
    }

    // flattens a parse tree 
    void flattenTree(SceneNode *root, Matrix acc) {
        // apply transformations to acc (an accumulator for transformations)
        size_t ntrans = root->transformations.size();
        for (size_t i = 0; i < ntrans; i++) {
            SceneTransformation *trans = root->transformations[i];
            acc = getMatrixFromTransform(trans) * acc;
        }

        // push each obj in root
        size_t nobjs = root->primitives.size();
        for (size_t i = 0; i < nobjs; i++) {
            transforms.push_back(acc);
            

        }

        // recurse on children
    }
};


#endif
