#include "linearcongruentrandomizer.hpp"

LinearCongruentRandomizer::LinearCongruentRandomizer() {}

#include <QDebug>
QVector<long> LinearCongruentRandomizer::createRandomSequence(
    int numberOfRequiredDigits,
    int numberOfElements) {
  if (numberOfElements < 1 || numberOfRequiredDigits < 1) {
    return QVector<long>();
  }

  QVector<long> sequence = QVector<long>();

  long requiredDigitsDivider = pow(10, numberOfRequiredDigits);
  long minAppendValue = requiredDigitsDivider / 10;
  if (numberOfRequiredDigits == 1)
    minAppendValue = 0;
  long numberToAppend;
  for (int i = 0; i < numberOfElements; i++) {
    curElement = curElement * 84589 + 15989;
    numberToAppend =
        ((unsigned int)curElement % 217728) % requiredDigitsDivider;

    if (numberToAppend >= minAppendValue) {
      sequence.append(numberToAppend);
    } else {
      i--;
    }
  }

  return sequence;
}

void LinearCongruentRandomizer::setSeed(long seed) {
  curElement = seed;
}
