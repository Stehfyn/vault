<!-- generated-from-dump2 -->
# Electric Field Lines Simulation

Adrian Roman's pedagogical physics simulation — given a set of point charges, integrate the electric field lines outward from each charge and draw the perpendicular equipotential surfaces, using fixed-step and adaptive Runge-Kutta (RK4 / RKF45 / Dormand-Prince) for the streamline integration. The interesting bit is the adaptive step-size logic: near a charge the field diverges as 1/r^2 so the integrator has to take much smaller steps than it does in the comparatively flat regions between charges. Same author maintains a long series of similar C++/MFC educational physics demos (quantum well, double pendulum, lattice Boltzmann, etc.) which together form a decent reference for "how do you actually code up the simulation behind a physics textbook figure."

```cpp
// RK4 streamline step for the E-field of a set of point charges.
Vec3 E_field(const Vec3& p, const std::vector<PointCharge>& charges) {
    Vec3 e{0,0,0};
    for (auto& c : charges) {
        Vec3 r = p - c.pos;
        double r2 = r.dot(r);
        e += (c.q / (r2 * std::sqrt(r2))) * r;  // k=1 in natural units
    }
    return e;
}

Vec3 rk4_step(const Vec3& p, double h, const std::vector<PointCharge>& q) {
    Vec3 k1 = E_field(p,           q).normalized();
    Vec3 k2 = E_field(p + 0.5*h*k1,q).normalized();
    Vec3 k3 = E_field(p + 0.5*h*k2,q).normalized();
    Vec3 k4 = E_field(p +     h*k3,q).normalized();
    return p + (h/6.0) * (k1 + 2*k2 + 2*k3 + k4);
}
```

## References
- <https://github.com/aromanro/ElectricField>
