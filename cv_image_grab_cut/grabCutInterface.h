#ifndef GRABCUTINTERFACE_H
#define GRABCUTINTERFACE_H

#include <Eigen/Dense>
#include <array>
#include <vector>


struct point {
  int row;
  int col;
};

// using ARGB = uint32_t;

void grab_cut(const void *const data_8UC3_row_major, const int rows,
              const int cols, const std::array<point, 2> &rect,
              std::vector<Eigen::ArrayXX<bool>> *const large_segments,
              std::vector<point> *const dots);

void fun();

#endif // GRABCUTINTERFACE_H