### Extended Kalman Filter Project Starter Code
Self-Driving Car Engineer Nanodegree Program

In this project I utilize a kalman filter to estimate the state of a moving object of interest with noisy lidar and radar measurements. 
The Kalman Filter takes the mean and variance for each dimension of the moving object and put them into a “state” vector and “covariance” matrix, respectively. From there, the principle of the Kalman filter is just a cycle of prediction based on previous motion and measurement update based on the sensor belief, from which a compromise is made and a new state vector and covariance matrix are determined. The Extended Kalman Filter simply adapts modifies this simple linear model to account for nonlinear relationships between current/previous states and states/measurements.

This project involves the use of a simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases)

This repository includes two files that can be used to set up and install [uWebSocketIO](https://github.com/uWebSockets/uWebSockets) for either Linux or Mac systems. For windows you can use either Docker, VMware, or even [Windows 10 Bash on Ubuntu](https://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/) to install uWebSocketIO. Please see the uWebSocketIO Starter Guide page in the classroom within the EKF Project lesson for the required version and installation scripts.

Once the install for uWebSocketIO is complete, the main program can be built and run by doing the following from the project top directory.

1. mkdir build
2. cd build
3. cmake ..
4. make
5. ./ExtendedKF

