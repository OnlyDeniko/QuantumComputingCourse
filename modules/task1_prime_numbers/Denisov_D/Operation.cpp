#include"Operation.h"
ll Mult(ll x, ll y, ll N)
{
 /* ll temp_x = 1, ans = y, save_y = y;//works much longer
  while (x != 1)
  {
    if (temp_x * 2 < x) {
      y += y;
      y %= N;
      temp_x *= 2;
    }
    else
    {
      x -= temp_x;
      temp_x = 1;
      ans = ans + y;
      ans %= N;
      y = save_y;
    }
  }
  return ans;*/
  if (y == 0)
    return 0;
  ll z = Mult(x, y / 2, N);
  if (z > N)
    z %= N;
  if (y % 2 == 0)
    return z + z;
  else
    return x + z + z;
}

ll NOD(ll x, ll y)
{
  if (y == 0)
    return x;
  return NOD(y, x % y);
}

ll mod_pow(ll x, ll y, ll N)
{
  if (y == 0)
    return 1;
  ll z = mod_pow(x, y / 2, N);
  if (y % 2 == 0)
  {
    z = Mult(z, z, N);
    return z % N;
  }
  z = Mult(z, z, N);
  if (z > N)
    z %= N;
  z = Mult(z, x, N);
  if (z > N)
    z %= N;
  return z;
}


bool Farm_s_test(ll number)
{
  if (number == 2 || number == 3)
    return true;
  int counter = 0, attempts = 3;
  while (counter <= attempts)
  {
    ll temp = counter + 2;
    if (NOD(temp, number) != 1)
    {
      attempts++;
    }
    else if ((mod_pow(temp, number - 1, number)) != 1)
      return false;
    counter++;
  }
  return true;
}

bool RobinMiller_test(ll number)
{
  if (number == 2 || number == 3)
    return true;
  int tryes = 5, t_2 = 0;
  ll alpha = number - 1;
  while (alpha % 2 != 1)
  {
    t_2++;
    alpha >>= 1;
  }
  for (int i = 0; i < tryes; i++)
  {
    bool f = false;
    ll temp = rand() % (number - 3) + 2;
    ll x = mod_pow(temp, alpha, number);
    if (x == 1 || x == number - 1)
      continue;
    for (int i = 0; i < t_2 - 1; i++)
    {
      x = mod_pow(x, 2, number);
      if (x == 1)
        return false;
      if (x == number - 1)
      {
        f = true;
        break;
      }
    }
    if (!f)
      return false;
  }
  return true;
}
