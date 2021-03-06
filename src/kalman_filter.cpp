#include "kalman_filter.h"
#include <iostream>
using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;
const float PI  =3.1416;
/* 
 * Please note that the Eigen library does not initialize 
 *   VectorXd or MatrixXd objects with zeros upon creation.
 */

KalmanFilter::KalmanFilter() {}

KalmanFilter::~KalmanFilter() {}

void KalmanFilter::Init(VectorXd &x_in, MatrixXd &P_in, MatrixXd &F_in,
                        MatrixXd &H_in, MatrixXd &R_in, MatrixXd &Q_in) {
  x_ = x_in;
  P_ = P_in;
  F_ = F_in;
  H_ = H_in;
  R_ = R_in;
  Q_ = Q_in;
}

void KalmanFilter::Predict() {
 
  x_ = F_*x_;
  P_ = F_ * P_ * F_.transpose() + Q_;
}

void KalmanFilter::Update(const VectorXd &z) {
  
  VectorXd z_pred = H_ * x_;
  VectorXd y = z - z_pred;
  MatrixXd S = (H_ * P_ * H_.transpose()) + R_;
  MatrixXd Sinv = S.inverse();
  MatrixXd K = (P_ * H_.transpose())*Sinv;
  x_ = x_ + (K * y);
  long x_size = x_.size();
  MatrixXd I_ = MatrixXd::Identity(x_size, x_size);
  P_ = (I_- K * H_) * P_;
}



void KalmanFilter::UpdateEKF(const VectorXd &z) {
 
  float px = x_[0];
  float py = x_[1];
  float vx = x_[2];
  float vy = x_[3];
  float rho = sqrt(px*px + py*py);
  float phi = 0.0;
  float rhodot = 0.0;
  phi = atan2(py , px);
  rhodot = ((px * vx + py * vy) / rho);
  
  VectorXd z_pred(3);
  z_pred <<rho, phi, rhodot;
  VectorXd y = z - z_pred;
  
 //Normalize phi
  while (y(1) < -PI) 
  {
    y(1) += 2 * PI;
  }
  while (y(1) > PI) 
  {
    y(1) -= 2 * PI;
  }
  
  if(y(1) > PI || y(1) < -PI)
  {
    std::cout << " phi is not within range" << std::endl;
  }
  
  MatrixXd S = H_ * (P_ * H_.transpose()) + R_;
  MatrixXd Sinv = S.inverse();
  MatrixXd K = (P_ * H_.transpose())*Sinv;
  x_ = x_ + (K * y);
  long x_size = x_.size();
  MatrixXd I_ = MatrixXd::Identity(x_size, x_size);
  P_ = (I_- K * H_) * P_;
}
  
  
