#ifndef NTTIMEDERIVATIVE_H
#define NTTIMEDERIVATIVE_H

#include "ScalarTransportTimeDerivative.h"

// Forward Declaration
class NtTimeDerivative;

template <>
InputParameters validParams<NtTimeDerivative>();

class NtTimeDerivative : public ScalarTransportTimeDerivative
{
public:
  NtTimeDerivative(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

  const MaterialProperty<std::vector<Real>> & _recipvel;
  const MaterialProperty<std::vector<Real>> & _d_recipvel_d_temp;
  unsigned int _group;
  unsigned int _temp_id;
};

#endif // NTTIMEDERIVATIVE_H
