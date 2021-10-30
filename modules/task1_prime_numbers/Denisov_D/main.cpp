//#define DEBUG
//#define tests
const int max_sign_num = 25;
static int counter_prime = 0;
static int counter_composite = 0;
static int countrer_carmichael = 0;
#include"Operation.h"
int main(int argc, char* argv[], char** env)
{
  auto start1 = std::chrono::steady_clock::now();
  srand(time(NULL));
  char* filein = argv[1];
  char* fileout = argv[2];
  std::ofstream fout;
  std::ifstream fin;
  std::vector<ll>numbers;
#ifndef DEBUG
  if (argc < 3)
  {
    std::cout << "Not enough parameters\n";
    return 0;
  }
  fin.open(filein);
  fout.open(fileout);
  fout.close();
#else
  fout.open("output_file.txt");
  fout.close();
  fin.open("carmichael1.txt");
#endif //DEBUG
  if (!fin.is_open())
  {
    std::cout << "filein open error\n";
    return 0;
  }
  while (!fin.eof())
  {
    std::string str = "";
    getline(fin, str);
    char s[max_sign_num]{};
#ifdef tests
    int k = 0;
  while (str[k] != ' ')
    k++;
  for (size_t i = 0; i < str.size()-k; i++)
  {
    s[i] = str[i+k+1];
    s[str.size()-k-1] = '\0';
  }
#else
    for (size_t i = 0; i < str.size(); i++)
    {
      s[i] = str[i];
    }
    s[str.size()] = '\0';
#endif // tests
    numbers.push_back(std::atoll(s));
  }
  fin.close();



  double max = 0;
  double medium = 0;
  //////////////////////////////////////////////
  for (size_t i = 0; i < numbers.size(); i++)
  {
#ifndef DEBUG
    fout.open(fileout, std::ofstream::app);
#else
    fout.open("output_file.txt", std::ofstream::app);
#endif // DEBUG
    bool Farm = false;
    std::string str = std::to_string(numbers[i]);
    auto start = std::chrono::steady_clock::now();
    if (!Farm_s_test(numbers[i])) {
      fout << str << " [composite] - Farm's test,\t";
    }
    else
    {
      Farm = true;
     fout << str << " [prime] - Farm's test, \t";
    }

    if (!Farm)
    {
     fout << str << " [composite] - Robin-Miller's test, ";
      counter_composite++;
    }
    else if (RobinMiller_test(numbers[i]))
    {
      fout << str << " [prime] - Robin-Miller's test, ";
      counter_prime++;
    }
    else
    {
      fout << str << " [carmichael] - Robin-Miller's test, ";
      countrer_carmichael++;
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    if (elapsed_seconds.count() > max)
      max = elapsed_seconds.count();
    medium += elapsed_seconds.count();
   // std::cout << elapsed_seconds.count() * 1000 << "ms\n";
    fout << elapsed_seconds.count() * 1000  << "ms\n";
    fout.close();
  }
  /////////////////////////////////////////////
  auto end1 = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = end1 - start1;
  std::cout << "composite numbers = " <<counter_composite << "\n";
  std::cout << "prime numbers = " << counter_prime << "\n";
  std::cout << "carmichael numbers = " << countrer_carmichael << "\n";
  std::cout << "the longest check = " << max*1000 << "ms\n";
  std::cout << "average check = " << medium/numbers.size()*1000 << "ms\n";
  //fout.close();
  return 0;
}
