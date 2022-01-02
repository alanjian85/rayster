#ifndef RAYSTER_MATRIX4_HPP
#define RAYSTER_MATRIX4_HPP

#include <cstdlib>

#include "position3.hpp"
#include "vector3.hpp"

namespace rayster {
    class matrix4 {
    public:
        using size_type = std::size_t;
    
        matrix4() = default;
        matrix4(double e00, double e01, double e02, double e03,
                double e10, double e11, double e12, double e13,
                double e20, double e21, double e22, double e23,
                double e30, double e31, double e32, double e33)
        {
            entries_[0][0] = e00; entries_[0][1] = e10; entries_[0][2] = e20; entries_[0][3] = e30;
            entries_[1][0] = e01; entries_[1][1] = e11; entries_[1][2] = e21; entries_[1][3] = e31;
            entries_[2][0] = e02; entries_[2][1] = e12; entries_[2][2] = e22; entries_[2][3] = e32;
            entries_[3][0] = e03; entries_[3][1] = e13; entries_[3][2] = e23; entries_[3][3] = e33;
        }

        double& operator()(size_type i, size_type j) noexcept {
            return entries_[j][i];
        }

        const double& operator()(size_type i, size_type j) const noexcept {
            return entries_[j][i];
        }

        matrix4 transpose() const noexcept {
            matrix4 res;
            res.entries_[0][0] = entries_[0][0]; res.entries_[0][1] = entries_[1][0]; res.entries_[0][2] = entries_[2][0]; res.entries_[0][3] = entries_[3][0];
            res.entries_[1][0] = entries_[0][1]; res.entries_[1][1] = entries_[1][1]; res.entries_[1][2] = entries_[2][1]; res.entries_[1][3] = entries_[3][1];
            res.entries_[2][0] = entries_[0][2]; res.entries_[2][1] = entries_[1][2]; res.entries_[2][2] = entries_[2][2]; res.entries_[2][3] = entries_[3][2];
            res.entries_[3][0] = entries_[0][3]; res.entries_[3][1] = entries_[1][3]; res.entries_[3][2] = entries_[2][3]; res.entries_[3][3] = entries_[3][3];
            return res;
        }
    private:
        double entries_[4][4];
    };

    matrix4 operator*(matrix4 lhs, matrix4 rhs) noexcept;
    vector3 operator*(matrix4 lhs, vector3 rhs) noexcept;
    position3 operator*(matrix4 lhs, position3 rhs) noexcept;
}

#endif