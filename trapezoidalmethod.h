#ifndef TRAPEZOIDALMETHOD_H
#define TRAPEZOIDALMETHOD_H

#include <QWidget>
#include "odesolverbase.h"

namespace Ui {
class TrapezoidalMethod;
}

class TrapezoidalMethod : public ODESolverBase{
   Q_OBJECT

public:

   explicit TrapezoidalMethod(ODESolverBase *parent = nullptr);

   ~TrapezoidalMethod () override;

   void makepoints() override;
};

#endif // TRAPEZOIDALMETHOD_H
