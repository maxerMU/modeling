#ifndef MYCRITEIRIUM_H
#define MYCRITEIRIUM_H

#include <QVector>

class MyCriteirium {
 public:
  MyCriteirium();
  double findPValue(const QVector<long>& results, long min, long max);
};

#endif  // MYCRITEIRIUM_H
