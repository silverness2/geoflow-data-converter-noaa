//==============================================================================
// Date        : 3/23/21 (SG)
// Description : Stores location and data value of a GeoFLOW node.
// Copyright   : Copyright 2021. Regents of the University of Colorado.
//               All rights reserved.
//==============================================================================

#ifndef GNODE_H
#define GNODE_H

#include <iostream>
#include <vector>
#include <array>

#include "gtypes.h"

using namespace std;

template <class T>
class GNode
{
public:
    GNode(const T& x, 
          const T& y, 
          const T& z, 
          const T& val, 
          const GSIZET& layerID=0)
    {
        // Initialize
        _pos = {{x, y, z}};
        _val = val;
        _layerID = layerID;
        _latlon = {{0, 0}};
        _radius = 0;
    }
    ~GNode() {}

    // Accessors
    array<T, 3> pos() const { return _pos; }
    void pos(const array<T, 3>& pos) { _pos = pos; }
    array<T, 2> latlon() const { return _latlon; }
    void latlon(const array<T, 2>& latlon) { _latlon = latlon; }
    T radius() const { return _radius; }
    void radius(const T& radius) { _radius = radius; }

    // Print helpers
    void printNode()
    {
        cout << "Node: ";
        cout << "(x, y, z): (" << _pos[0] << ", " 
                               << _pos[1] << ", "
                               << _pos[2] << ") | ";
        cout << "(lat, lon, r): (" << _latlon[0] << ", " 
                                   << _latlon[1] << ", "
                                   << _radius << ") | ";
        cout << "layerID: (" << _layerID << ") | ";
        cout << "val: (" << _val << ")";
        cout << endl;
    }

private:
    array<T, 3> _pos;    // cartesian coordinate x,y,z of node
    array<T, 2> _latlon; // lat,lon coordinate of node
    T _val;              // data value at node
    T _radius;           // radius of node
    GSIZET _layerID;     // layer index the node resides on
};

#endif