#pragma once
#define ll unsigned long long int
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include <chrono>
#include<ctime>
ll Mult(ll x, ll y,ll N)
{
  if (y == 0)
    return 0;
  ll z = Mult(x, y / 2,N);
  if (z > N)
    z %= N;
  if (y % 2 == 0)
    return z + z;
  else
    return x + z + z;
}

ll NOD(ll x, ll y)
{
  if (x < y)
  {
    ll temp = x;
    x = y;
    y = temp;
  }
  if (y == 0)
    return x;
  return NOD(y, x % y);
}

ll mod_pow(ll x, ll y, ll N)
{
  if (y == 0)
    return 1;
  ll z = mod_pow(x, y /2, N);
  if (y % 2 == 0)
  {
    z= Mult(z, z, N);
    if(z > N)
      z %= N;
    return z;
  }
  z= Mult(z, z, N);
  if (z > N)
    z %= N;
  z= Mult(z, x, N);
  if (z > N)
    z %= N;
  return z;
}


bool Farm_s_test(ll number)
{
  if (number == 2 || number == 3)
    return true;
  ll counter = 0, attempts = 3;
  while (counter <= attempts)
  {
    ll temp = counter + 2;
    if (NOD(temp, number) != 1)
    {
      /*std::ofstream f;
      f.open("fff.txt",std::ofstream::app);
      f << number << "/" << NOD(temp,number) << "\n";
      f.close();
      return false;*/
      attempts++;
    }
    else if ((mod_pow(temp, number-1, number)) % number !=1)
      return false;
    counter++;
  }
  return true;
}

bool RobinMiller_test(ll number)
{
  //if (number != 2 && number != 3 && (number % 2 == 0 || number % 3 == 0))
  //  return false;
  if (number == 2 || number == 3)
    return true;
  ll tryes = 25, alpha = number - 1;
  ll t_2 = 0;
  while (alpha % 2 != 1)
  {
    t_2++;
    alpha *= 0.5;
  }
  for (ll i = 0; i < tryes; i++)
  {
    bool f = false;
    ll temp = rand() % (number - 3) + 2;
    ll x = mod_pow(temp, alpha, number);
    if (x == 1 || x == number - 1)
      continue;
    for (ll i = 0; i < t_2-1 ; i++)
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
    if(!f)
    return false;
  }
  return true;
}
