#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <math.h> 

using namespace std;

int main (int argc, char** argv)
{
  float pi = 3.14159265;
  float n = 180;
  string pcd_file_path = "./hello_pcl.pcd";
  // x^2 + y^2 + z^2 = r^2
  // (r*cos(a)*cos(p), r*cos(a)*sin(p), r*sin(a))
  vector<vector<float>> xyz; 
  for (float i = 0; i <= n; i++) {
    for (float j = 0; j <= n; j++) {
        xyz.push_back({cos(i*pi/n)*cos(j*pi/n), cos(i*pi/n)*sin(j*pi/n), sin(i*pi/n)});
    }
  }
  // Fill in the cloud data 
  pcl::PointCloud<pcl::PointXYZRGB> cloud;
  cloud.width  = xyz.size();
  cloud.height = 1;
  cloud.points.resize (cloud.width * cloud.height);

  int k = 0;
  for (auto& point: cloud)
  {
    point.x = xyz[k][0];
    point.y = xyz[k][1];
    point.z = xyz[k][2];
    point.r = (uint8_t) (255.0f*rand()/(RAND_MAX + 1.0f));
    point.g = (uint8_t) (255.0f*rand()/(RAND_MAX + 1.0f));
    point.b = (uint8_t) (255.0f*rand()/(RAND_MAX + 1.0f));
    k++;
  }
  // save cloud points to a pcd file
  pcl::io::savePCDFileASCII(pcd_file_path, cloud);
  return (0);
}
