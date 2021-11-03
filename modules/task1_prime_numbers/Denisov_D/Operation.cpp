#include"Operation.h"
ll Mult(ll x, ll y, ll N)
{
  if (y == 0)
  {
    return 0;
  }

 ll z = Mult(x, y / 2, N);

  if (y % 2 == 0)
  {
    return ((2 * z) % N);
  }
  else
  {
    return ((x + ((2 * z) % N)) % N);
  }
}

ll NOD(ll x, ll y)
{
  if (y == 0)
    return x;
  return NOD(y, x % y);
}

ll mod_pow(ll a, ll b, ll N) {
  ll ans = 1;
  while (b) {
    if (b & 1) {
      ans = Mult(ans, a, N);
    }
    b >>= 1;
    a = Mult(a, a, N);
  }
  return ans;
}


bool Farm_s_test(ll number)
{
  if (number == 2 || number == 3)
    return true;
  int counter = 0, attempts = 3;
  while (counter <= attempts)
  {
    ll temp = (ll)counter + 2;
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

    std::mt19937 gen;
    std::uniform_int_distribution<ll> uid(2, number - 2);
    gen.seed(rand());
    ll temp = uid(gen);

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
