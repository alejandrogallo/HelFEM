/*
 *                This source code is part of
 *
 *                          HelFEM
 *                             -
 * Finite element methods for electronic structure calculations on small systems
 *
 * Written by Susi Lehtola, 2018-
 * Copyright (c) 2018- Susi Lehtola
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */
#ifndef LEGENDRE_TABLE_H
#define LEGENDRE_TABLE_H

#include <vector>
#include <armadillo>

namespace helfem {
  namespace legendretable {
    typedef struct {
      /// Value of argument
      double xi;
      /// Plm values
      arma::mat Plm;
      /// Qlm values
      arma::mat Qlm;
    } legendre_table_t;

    bool operator<(const legendre_table_t & lh, const legendre_table_t & rh);

    class LegendreTable {
    private:
      /// Storage array
      std::vector<legendre_table_t> stor;
      /// Maximum L value used in the actual computation
      int Lpad;
      /// Maximum L value
      int Lmax;
      /// Maximum M value
      int Mmax;

      /// Find index in array
      size_t get_index(double xi, bool check=true) const;

    public:
      /// Dummy constructor
      LegendreTable();
      /// Constructor
      LegendreTable(int Lpad, int Lmax, int Mmax);
      /// Destructor
      ~LegendreTable();
      /// Add value to table
      void compute(double xi);

      /// Get value from table
      double get_Plm(int l, int m, double xi) const;
      /// Get value from table
      double get_Qlm(int l, int m, double xi) const;

      /// Get value from table
      arma::vec get_Plm(int l, int m, const arma::vec & xi) const;
      /// Get value from table
      arma::vec get_Qlm(int l, int m, const arma::vec & xi) const;
    };
  }
}

#endif
