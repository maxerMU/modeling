#include "mycriteirium.h"
#include <vector>

MyCriteirium::MyCriteirium() {}

double MyCriteirium::findPValue(const QVector<long>& results,
                                long min,
                                long max) {
  // min max args
  // step = 1
  // freq
  std::vector<long> freqs(max - min + 1);
  for (auto res : results)
    freqs[res - min] += 1;

  // mid freq
  double freq_mean = 0;
  for (auto freq : freqs) {
    freq_mean += (double)freq / freqs.size();
  }
  // disp max disp
  double freq_disp = 0;
  for (auto freq : freqs) {
    freq_disp +=
        (double)((freq - freq_mean) * (freq - freq_mean)) / freqs.size();
  }
  // max disp = (n / size - size) ^ 2 + (size - 1) * (n / size) ^ 2
  double max_mean = (double)results.size() / freqs.size();
  double max_disp = ((max_mean - freqs.size()) * (max_mean - freqs.size()) +
                     (freqs.size() - 1) * max_mean * max_mean) /
                    freqs.size();

  // 1 - disp / max disp
  return 1 - freq_disp / max_disp;
}
