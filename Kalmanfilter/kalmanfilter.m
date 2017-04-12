function y = kalmanfilter(z, u)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
dt = 0.01;
k1 = 1;
k2 = 1;
k3 = 1;
k4 = 1;

A = [1 0 0 0 dt 0 0 0;
    0 1 0 0 0 dt 0 0;
    0 0 1 0 0 0 dt 0;
    0 0 0 1 0 0 0 dt;
    0 0 0 0 1 0 0  0;
    0 0 0 0 0 1 0  0;
    0 0 0 0 0 0 1  0;
    0 0 0 0 0 0 0  1];

H = [1 0 0 0 0 0 0 0;
    0 1 0 0 0 0 0 0;
    0 0 1 0 0 0 0 0;
    0 0 0 1 0 0 0 0];

% H = [1 0 0 0 0 0 0 0;
%     0 1 0 0 0 0 0 0;
%     0 0 1 0 0 0 0 0;
%     0 0 0 1 0 0 0 0;
%     0 0 0 0 1 0 0 0;
%     0 0 0 0 0 1 0 0];

Q = eye(8);
R = 1000 * eye(6);
persistent x_est p_est                % Initial state conditions
if isempty(x_est)
    x_est = zeros(8, 1);             % x_est=[x,y,z,chi,x_p,y_p,z_p,chi_p]'
    p_est = zeros(8, 8);
end
chi = x_est(4);
B = [0 0 0 0;
    0 0 0 0;
    0 0 0 0;
    0 0 0 0;
    k1*cos(chi) -k2*sin(chi) 0 0;
    k1*sin(chi)  k2*cos(chi) 0 0;
    0 0 k3 0;
    0 0 0 k4];
% Predicted state and covariance
x_prd = A * x_est + B * u';
p_prd = A * p_est * A' + Q;
% Estimation
S = H * p_prd * H' + R;
B = p_prd * H';
klm_gain = (B \ S)';
% Estimated state and covariance
x_est = x_prd + klm_gain * (z - H * x_prd);
p_est = p_prd - klm_gain * H * p_prd;
% Compute the estimated measurements
% y = H * x_est;
% Compute the estimated state
y = x_est;
end                % of the function