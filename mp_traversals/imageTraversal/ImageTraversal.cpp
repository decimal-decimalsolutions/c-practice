#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"
#include <queue>

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 * 
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  _reachEnd = false;
}

/**
 * check if meetTolerance
 */
bool ImageTraversal::Iterator::meetTolerance(const Point p){
  //Check if this mark all the points that cab be visited
  if (p.x >= _png.width() || p.y >= _png.height())
    return false;

  HSLAPixel start = (_png.getPixel(_startPoint.x, _startPoint.y));
  HSLAPixel desired = (_png.getPixel(p.x, p.y));
  if (calculateDelta(start, desired) >= _tolerance)
    return false;

  return true;
}

/**
 * New added constructor
 */
ImageTraversal::Iterator::Iterator(ImageTraversal *traversal, PNG png, Point startPoint, double tolerance){
  //set the class variables so that it can be used by other methods
  _startPoint = startPoint;
  _originalStartPoint = startPoint;
  _tolerance = tolerance;
  _png = png;
  _traversal = traversal;

  for (unsigned i = 0; i < _png.width() * _png.height(); i++) {
    _visited.push_back(false);
  }
  _reachEnd = false;

//--------------------------

  //Check if this mark all the points that cab be visited
  if (startPoint.x >= _png.width() || startPoint.y >= _png.height())
    _reachEnd =  false;

  HSLAPixel start = (_png.getPixel(_originalStartPoint.x, _originalStartPoint.y));// startPoint and OriginalPOint are same
  HSLAPixel desired = (_png.getPixel(startPoint.x, startPoint.y));
  if (calculateDelta(start, desired) >= _tolerance) {
    _reachEnd = true;
  }else{
    _traversalPath.push_back(startPoint);
    _visited[startPoint.x + startPoint.y * _png.width()] = true;
  }
}


/**
 * Iterator increment oprator
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {

  /** @todo [Part 1] */

  Point p1 = Point(_startPoint.x + 1, _startPoint.y);
  Point p2 = Point(_startPoint.x, _startPoint.y + 1);
  Point p3 = Point(_startPoint.x-1, _startPoint.y);
  Point p4 = Point(_startPoint.x, _startPoint.y - 1);

  if (meetTolerance(p1)){
    _traversal->add(p1);
  }
  if (meetTolerance(p2)){
    _traversal->add(p2);
  }
  if (meetTolerance(p3)) {
    _traversal->add(p3);
  }
  if (meetTolerance(p4)) {
    _traversal->add(p4);
  }


  if (_traversal->empty()) {
      _reachEnd = true;
      return *this;
  }


  Point next = _traversal->pop();
  while (_visited[next.x + next.y * _png.width()]) {
    if (!_traversal->empty()) {
      next = _traversal->pop();
    }else {
      _reachEnd = true;
      return *this;
    }
  }
  _startPoint =  next;
  _visited[_startPoint.x + _startPoint.y * _png.width()] = true;
  _traversalPath.push_back(_startPoint);
  return *this;
}


/**
 * Iterator accessor opreator.
 * 
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
    //  return Point(0, 0);
    return _startPoint;
}

/**
 * Iterator inequality operator.
 * 
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  return other._reachEnd!=_reachEnd;

}


