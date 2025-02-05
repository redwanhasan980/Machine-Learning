#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int total_num = 15;
  bool converged = false;
  int iteration = 0;
  int data_size = 3;
  vector<vector<int>> data;
  for (int i = 0; i < total_num; i++)
  {
    int x1, x2, y;
    cin >> x1 >> x2 >> y;
    data.push_back({1, x1, x2, y});
  }
  vector<double> weights(data_size, 0.0);
  while (iteration < 100 && !converged)
  {
    converged = true;

    for (int i = 0; i < total_num; i++)
    {
      int y = data[i][data_size];
      int sum = 0;
      for (int j = 0; j < data_size; j++)
      {
        sum += (data[i][j] * weights[j]);
      }
      if (sum * y <= 0)
      {
        converged = false;
        for (int j = 0; j < data_size; j++)
        {
          weights[j] = weights[j] + y * data[i][j];
        }
      }
    }
    iteration++;
  }
  int testx1 = 190, testx2 = 120;
  int sum = testx1 * weights[1];
  sum += testx2 * weights[2];
  // cout<<sum<<endl;
  for (int i = 0; i < data_size; i++)
    cout << weights[i] << " ";
  cout << endl;
  int prediction;
  if (sum <= 0)
    prediction = -1;
  else
    prediction = 1;
  if (prediction == -1)
    cout << "Not Obese" << endl;
  else
    cout << "Obese" << endl;

  return 0;
}