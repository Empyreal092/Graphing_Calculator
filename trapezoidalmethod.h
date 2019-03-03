#ifndef TRAPEZOIDALMETHOD_H
#define TRAPEZOIDALMETHOD_H

#include <QWidget>
#include "eulermethod.h"

namespace Ui {
class TrapezoidalMethod;
}

class TrapezoidalMethod : public EulerMethod{
   Q_OBJECT

public:

   explicit TrapezoidalMethod(EulerMethod *parent = nullptr);

   ~TrapezoidalMethod () override;

   void makepoints() override;
};

#endif // TRAPEZOIDALMETHOD_H
