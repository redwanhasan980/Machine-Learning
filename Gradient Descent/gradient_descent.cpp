#include <bits/stdc++.h>
using namespace std;

int total_num = 100;
int iteration = 100;
int data_size = 3;
int i, j;
vector<double> weights(data_size, 0.0);

vector<vector<double>> x;
vector<double> y;
double alpha = 0.1; // learning rate

double cal_xw(int i)
{
  double xwi = 0.0;
  for (j = 0; j < data_size; j++)
  {
    xwi += x[i][j] * weights[j];
  }
  return xwi;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  weights[0] = 2.0;
  weights[1] = 3.0;
  double x1, x2, y0;
  for (i = 0; i < total_num; i++)
  {
    cin >> x1>>x2;
    x.push_back({1.0, x1,x2});
  }
  for (i = 0; i < total_num; i++)
  {

    cin >> y0;
    y.push_back(y0);
  }

  
  while (iteration--)
  { 
    vector<double> h(total_num, 0.0);
    for (i = 0; i < total_num; i++)
    {
      double xwi = cal_xw(i);
      h[i] += xwi;
    }
    vector<double> gradients(data_size, 0.0);
    for (j = 0; j < data_size; j++)
    {
      for (i = 0; i < total_num; i++)
      {
        gradients[j] += (h[i] - y[i]) * x[i][j];
      }
      gradients[j] *= (2.0 / total_num);
    }
    for (int j = 0; j < data_size; ++j)
    {
      weights[j] -= alpha * gradients[j];
    }
  }

 
  for (int i = 0; i < data_size; i++)
    cout << weights[i] << " ";
  cout << endl;

  return 0;
}