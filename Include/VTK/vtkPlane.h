/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkPlane.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkPlane - perform various plane computations
// .SECTION Description
// vtkPlane provides methods for various plane computations. These include
// projecting points onto a plane, evaluating the plane equation, and 
// returning plane normal. vtkPlane is a concrete implementation of the 
// abstract class vtkImplicitFunction.

#ifndef __vtkPlane_h
#define __vtkPlane_h

#include "vtkImplicitFunction.h"

class VTK_COMMON_EXPORT vtkPlane : public vtkImplicitFunction
{
public:
  // Description
  // Construct plane passing through origin and normal to z-axis.
  static vtkPlane *New();

  vtkTypeRevisionMacro(vtkPlane,vtkImplicitFunction);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description
  // Evaluate plane equation for point x[3].
  double EvaluateFunction(double x[3]);
  double EvaluateFunction(double x, double y, double z)
    {return this->vtkImplicitFunction::EvaluateFunction(x, y, z); } ;

  // Description
  // Evaluate function gradient at point x[3].
  void EvaluateGradient(double x[3], double g[3]);

  // Description:
  // Set/get plane normal. Plane is defined by point and normal.
  vtkSetVector3Macro(Normal,double);
  vtkGetVectorMacro(Normal,double,3);

  // Description:
  // Set/get point through which plane passes. Plane is defined by point 
  // and normal.
  vtkSetVector3Macro(Origin,double);
  vtkGetVectorMacro(Origin,double,3);

  // Description:
  // Translate the plane in the direction of the normal by the
  // distance specified.  Negative values move the plane in the
  // opposite direction.
  void Push(double distance);

  // Description
  // Project a point x onto plane defined by origin and normal. The 
  // projected point is returned in xproj. NOTE : normal assumed to
  // have magnitude 1.
  static void ProjectPoint(double x[3], double origin[3], double normal[3], 
                           double xproj[3]);
  void ProjectPoint(double x[3], double xproj[3]);

  // Description
  // Project a point x onto plane defined by origin and normal. The 
  // projected point is returned in xproj. NOTE : normal does NOT have to 
  // have magnitude 1.
  static void GeneralizedProjectPoint(double x[3], double origin[3],
                                      double normal[3], double xproj[3]);
  void GeneralizedProjectPoint(double x[3], double xproj[3]);

  
  // Description:
  // Quick evaluation of plane equation n(x-origin)=0.
  static double Evaluate(double normal[3], double origin[3], double x[3]);

  // Description:
  // Return the distance of a point x to a plane defined by n(x-p0) = 0. The
  // normal n[3] must be magnitude=1.
  static double DistanceToPlane(double x[3], double n[3], double p0[3]);
  double DistanceToPlane(double x[3]);
  
  // Description:
  // Given a line defined by the two points p1,p2; and a plane defined by the
  // normal n and point p0, compute an intersection. The parametric
  // coordinate along the line is returned in t, and the coordinates of 
  // intersection are returned in x. A zero is returned if the plane and line
  // do not intersect between (0<=t<=1). If the plane and line are parallel,
  // zero is returned and t is set to VTK_LARGE_DOUBLE.
  static int IntersectWithLine(double p1[3], double p2[3], double n[3], 
                               double p0[3], double& t, double x[3]);
  int IntersectWithLine(double p1[3], double p2[3], double& t, double x[3]);

protected:
  vtkPlane();
  ~vtkPlane() {};

  double Normal[3];
  double Origin[3];

private:
  vtkPlane(const vtkPlane&);  // Not implemented.
  void operator=(const vtkPlane&);  // Not implemented.
};

inline double vtkPlane::Evaluate(double normal[3], 
                                 double origin[3], double x[3])
{
  return normal[0]*(x[0]-origin[0]) + normal[1]*(x[1]-origin[1]) + 
         normal[2]*(x[2]-origin[2]);
}

inline double vtkPlane::DistanceToPlane(double x[3], double n[3], double p0[3])
{
#define vtkPlaneAbs(x) ((x)<0?-(x):(x))
  return (vtkPlaneAbs(n[0]*(x[0]-p0[0]) + n[1]*(x[1]-p0[1]) + 
                      n[2]*(x[2]-p0[2])));
}

#endif


