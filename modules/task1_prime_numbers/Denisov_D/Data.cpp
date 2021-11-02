//#define ll unsigned long long int
////illustration
//ll Mult(ll x, ll y, ll N)
//{
//  //1
//  if (y == 0)
//    return 0;
//  ll z = Mult(x, y / 2, N);
//  if (z > N)
//    z %= N;
//  if (y % 2 == 0)
//    return z + z;
//  else
//    return x + z + z;
//
//  //2
//  ll temp_x = 1, ans = y, save_y = y;
//  while (x != 1)
//  {
//    if (temp_x * 2 < x)
//    {
//      y *= 2;
//      y %= N;
//      temp_x *= 2;
//    }
//    else
//    {
//      x -= temp_x;
//      temp_x = 1;
//      ans += y;
//      ans %= N;
//      y = save_y;
//    }
//  }
//
//  //3
//  ll ans = 0;
//  while (x != 0) {
//    if (x % 2 == 1)
//      ans += y;
//    ans %= N;
//
//    x >>= 1;
//    y <<= 1;
//    y %= N;
//  }
//  return ans;
//}
//
//ll mod_pow(ll x, ll y, ll N)
//{
//  //1 
//  if (y == 0)
//    return 1;
//  ll z = mod_pow(x, y / 2, N);
//  if (y % 2 == 0)
//  {
//    z = Mult(z, z, N);
//    return z % N;
//  }
//  z = Mult(z, z, N);
//  z %= N;
//  z = Mult(z, x, N);
//  return z % N;
//
//  //2
//  ll temp_x = 1, ans = y, save_y = y;
//  while (x != 1)
//  {
//    if (temp_x * 2 < x)
//    {
//      y *= y;
//      y %= N;
//      temp_x *= 2;
//    }
//    else
//    {
//      x -= temp_x;
//      temp_x = 1;
//      ans *= y;
//      ans %= N;
//      y = save_y;
//    }
//  }
//  return ans;
//}
