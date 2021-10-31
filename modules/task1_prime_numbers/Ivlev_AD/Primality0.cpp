#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

unsigned long long int ModMul(unsigned long long int a, unsigned long long int b, unsigned long long int M)
{
    unsigned long long int z = ModMul(a, b / 2, M);

    if (b % 2 == 0)
    {
        return ((2 * z) % M);
    }
    else
    {
        return ((a + ((2 * z) % M)) % M);
    }
}

unsigned long long int ModExp(unsigned long long int x, unsigned long long int n, unsigned long long int M)
{
    if (n == 0)
    {
        return 1;
    }

    unsigned long long int z = ModExp(x, n / 2, M);

    if (n % 2 == 0)
    {
        return ModMul(z, z, M);
    }
    else
    {
        return ModMul(ModMul(z, z, M), x, M);
    }
}

void PrimalityFerma0(unsigned long long int pnum, std::ofstream& out)
{
    auto start0 = std::chrono::steady_clock::now();

    bool check = 0;

    if (pnum % 2 != 0 && pnum % 3 != 0)
    {
        //unsigned long long int RandNum = 2 + rand() % (pnum - 2);
        std::mt19937 gen(128);
        std::uniform_int_distribution<unsigned long long int> uid(2, pnum - 2);
        unsigned long long int RandNum = uid(gen);
        RandNum = ModExp(RandNum, pnum - 1, pnum);

        if (RandNum != 1)
        {
            check = 1;
        }
    }
    else
    {
        check = 1;
    }

    auto end0 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds0 = end0 - start0;

    if (out.is_open())
    {
        out << "Ferma0_" << pnum << "_";
        if (check == 0)
        {
            out << "prime_";
        }
        else
        {
            out << "composite_";
        }
        out << "time: " << elapsed_seconds0.count() * 1000.0 << " millisecond\n";
    }
}

void PrimalityFerma1(unsigned long long int pnum, std::ofstream& out)
{
    auto start0 = std::chrono::steady_clock::now();

    bool check = 0;

    if (pnum % 2 != 0 && pnum % 3 != 0)
    {
        //unsigned long long int RandNum = 2 + rand() % (pnum - 2);
        std::mt19937 gen(128);
        std::uniform_int_distribution<unsigned long long int> uid(2, pnum - 2);
        unsigned long long int RandNum = uid(gen);

        for (size_t i = 0; i < 10; i++)
        {
            RandNum = ModExp(RandNum, pnum - 1, pnum);
            if (RandNum != 1)
            {
                check = 1;
                break;
            }
            //RandNum = 2 + rand() % (pnum - 2);
            RandNum = uid(gen);
        }
    }
    else
    {
        check = 1;
    }

    auto end0 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds0 = end0 - start0;

    if (out.is_open())
    {
        out << "Ferma1_" << pnum << "_";
        if (check == 0)
        {
            out << "prime_";
        }
        else
        {
            out << "composite_";
        }
        out << "time: " << elapsed_seconds0.count() * 1000.0 << " millisecond\n";
    }
}

void PrimalityMillerRabin(unsigned long long int pnum, std::ofstream& out)
{
    auto start0 = std::chrono::steady_clock::now();

    bool check = 0;

    if (pnum % 2 != 0 && pnum % 3 != 0)
    {
        for (size_t k = 0; k < 10; k++)
        {
            //unsigned long long int RandNum = 2 + rand() % (pnum - 2);
            std::mt19937 gen(128);
            std::uniform_int_distribution<unsigned long long int> uid(2, pnum - 2);
            unsigned long long int RandNum = uid(gen);

            unsigned long long int RandNumM = ModExp(RandNum, pnum - 1, pnum);

            if (RandNumM == 1)
            {
                unsigned long long int u = pnum - 1;
                unsigned long long int t = 0;

                while (u % 2 == 0) //pnum - 1 = (2^t)*u
                {
                    u /= 2;
                    t++;
                }

                unsigned long long int temp = pnum - 1;

                for (unsigned long long int i = 0; i <= t; i++)
                {
                    RandNumM = ModExp(RandNum, u, pnum);

                    if (RandNumM == 1)
                    {
                        if (temp != pnum - 1)
                        {
                            check = 1;
                        }

                        break;
                    }

                    temp = RandNumM;
                    u *= 2;
                }
            }
            else
            {
                check = 1;
                break;
            }
        }
    }
    else
    {
        check = 1;
    }

    auto end0 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds0 = end0 - start0;

    if (out.is_open())
    {
        out << "MillerRabin_" << pnum << "_";
        if (check == 0)
        {
            out << "prime_";
        }
        else
        {
            out << "composite_";
        }
        out << "time: " << elapsed_seconds0.count() * 1000.0 << " millisecond\n";
    }
}

int main(int argc, char* argv[], char* env[])
{
    auto start = std::chrono::steady_clock::now();

    std::ifstream FileIn(argv[1]);
    std::ofstream FileOut(argv[2]);

    if (FileIn.is_open() && FileOut.is_open())
    {
        unsigned long long int pnum = 0;
        while (!FileIn.eof())
        {
            FileIn >> pnum;

            PrimalityFerma0(pnum, FileOut);
            PrimalityFerma1(pnum, FileOut);
            PrimalityMillerRabin(pnum, FileOut);

            FileOut << "\n";
        }
    }
    else
    {
        std::cout << "The files are not open!\n";
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    FileOut << "Time since the start of the program: " << elapsed_seconds.count() * 1000.0 << " millisecond\n";

    FileIn.close();
    FileOut.close();
}
