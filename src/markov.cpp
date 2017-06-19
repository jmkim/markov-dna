#include "markov.hpp"

namespace markov_dna
{

Markov &
Markov::add (const std::string &dna_sequence)
{
  if (dna_sequence.length () != sequence_length_)
    { throw ("Sequence length is not match."); }

  sequences_.push_back (dna_sequence);

  SizeType idx_prev = sequences_.size () - 2UL;
  SizeType idx_new = sequences_.size () - 1UL;

  std::array<std::array<SizeType, 4>, 4> count_new = {0,};
  std::array<SizeType, 4> count_prev = {0,};

  for (SizeType i = 0; i < sequence_length_; ++i)
    {
      Dna prev_dna, new_dna;

      switch (sequences_.at (idx_prev).at (i))
        {
          case 'A': prev_dna = dna_A;
          break;
          case 'C': prev_dna = dna_C;
          break;
          case 'G': prev_dna = dna_G;
          break;
          case 'T': prev_dna = dna_T;
          break;
          default: throw ("Incorrect data was stored in 'sequences'.");
        }

      ++count_prev.at (prev_dna);

      switch (sequences_.at (idx_new).at (i))
        {
          case 'A': new_dna = dna_A;
          break;
          case 'C': new_dna = dna_C;
          break;
          case 'G': new_dna = dna_G;
          break;
          case 'T': new_dna = dna_T;
          break;
          default: throw ("Incorrect sequence was provided.");
        }

      ++count_new.at (prev_dna).at (new_dna);
    }

  Eigen::Matrix4d mat_prob_new;
  Eigen::Matrix4d mat_prob_comp;

  for (SizeType prev_dna = dna_A; prev_dna <= dna_T; ++prev_dna)
    {
      for (SizeType new_dna = dna_A; new_dna <= dna_T; ++new_dna)
        {
          mat_prob_new (prev_dna, new_dna) =
              count_new.at (prev_dna).at (new_dna) / (ProbabilityType) count_prev.at (prev_dna);
        }
    }

  if (probability_.size () > 0)
    { mat_prob_comp = mat_prob_new * probability_.at ((int) idx_prev - 1); }
  else
    { mat_prob_comp = mat_prob_new; }

  probability_.emplace (idx_new - 1, mat_prob_comp);

  return *this;
}

Markov &
Markov::printAll (void)
{
  for (int i = 0; i < sequences_.size () - 1; ++i)
    {
      std::cout << "\n";
      print (i);
    }

  return *this;
}

Markov &
Markov::print (int sequence)
{
  if (sequence == -1)
    { sequence = (int) probability_.size () - 1; }

  std::cout << probability_.at (sequence) << "\n";

  return *this;
}

}
