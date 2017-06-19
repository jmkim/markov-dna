#ifndef MARKOV_DNA_MARKOV_HPP
#define MARKOV_DNA_MARKOV_HPP

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>

#include <eigen3/Eigen/Dense>

namespace markov_dna
{

class Markov {
 public:
  typedef enum dna_t { dna_A = 0, dna_C = 1, dna_G = 2, dna_T = 3 } Dna;
  typedef unsigned long SizeType;
  typedef double ProbabilityType;

  Markov (const std::string &dna_sequence)
      : sequence_length_ (dna_sequence.length ())
  { sequences_.push_back (dna_sequence); }

  Markov (const Markov &markov)
      : sequence_length_ (markov.sequence_length_),
        sequences_ (markov.sequences_),
        probability_ (markov.probability_)
  {
  }

  Markov &add (const std::string &dna_sequence);
  Markov &printAll (void);
  Markov &print (int sequence = -1);

 private:
  SizeType sequence_length_;
  std::vector<std::string> sequences_;
  std::map<int, Eigen::Matrix4d> probability_;
};

}

#endif //MARKOV_DNA_MARKOV_HPP
