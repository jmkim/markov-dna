#include <iostream>
#include <array>
#include <ctime>

#include "../src/markov.hpp"

int
main (void)
{
  std::srand ((unsigned int) std::time (NULL));

  markov_dna::Markov markov ("TGCATTCCTAATATAAAAATGCTTCTCATA");
  markov.add ("GACTCTATATTAAAATTAAATCCCTATTTA")
      .add ("ATTGTCATTCACTAAACCAATAGAAAAGCG")
      .add ("AAATTTAGAGTTCTGTTCGTCTAATTAAAT")
      .add ("TTTTTATTAAAAAATTAGTTTAGATTATCT")
      .add ("GAGTTTATTTATTATGTATGCTTATAATAA")
      .add ("CTAAACTTAATAGTTTAGATAAAATTAATT")
      .add ("AACATGTAGTATATATAATTGCTGATGTAC")
      .add ("TCAAGTTTGGTAAACAACAACTTAAGAATT")
      .add ("ACCATATAGAATTCATCCATAATGTTAATA");

  for (int i = 0; i < 100; ++i)
    {
      std::string rand_str;
      for (int j = 0; j < 30; ++j)
        {
          switch (std::rand () % 4)
            {
              case 0: rand_str.append ("A");
              break;
              case 1: rand_str.append ("C");
              break;
              case 2: rand_str.append ("G");
              break;
              case 3: rand_str.append ("T");
              break;
              default:;
            }
        }
      markov.add (rand_str);
    }

  markov.printAll ();

  std::cout << "\nXs_new[0]: \n";
  markov_dna::Markov markov_test_0 (markov);
  markov_test_0.add ("ACTTTTCGAATATTAAAGTACAGTTTCATA").print ();

  std::cout << "\nXs_new[1]: \n";
  markov_dna::Markov markov_test_1 (markov);
  markov_test_1.add ("TAATATTTATTAAGGATGGCCCTAAATCTT").print ();

  std::cout << "\nXs_new[2]: \n";
  markov_dna::Markov markov_test_2 (markov);
  markov_test_2.add ("AATAGTAAACGTATTTGGTTTTTAAGATAA").print ();

  return 0;
}