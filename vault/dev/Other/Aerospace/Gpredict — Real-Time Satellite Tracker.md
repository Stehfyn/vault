<!-- generated-from-dump2 -->
# Gpredict — Real-Time Satellite Tracker

Alexandru Csete's real-time satellite tracker — propagates SGP4/SDP4 orbits from TLEs (typically pulled from CelesTrak), plots ground tracks, computes pass predictions (AOS/LOS/max-elevation) for any observer location, and drives rotators and radios over hamlib's `rotctld`/`rigctld` so an amateur-radio station can autotrack LEO sats while compensating for Doppler. Together with GQRX (same author) and a USB SDR, this is the standard open-source ground-station stack for working SO-50, the ISS APRS digipeater, NOAA APT weather sats, and the cubesat fleet. Caveats: SGP4 is only accurate for a few days from the TLE epoch (refresh weekly), and the UI is GTK and now showing its age.

```text
Standard workflow:
  1. File -> Update TLE from network (pulls latest from CelesTrak by category).
  2. Configure observer (lat/lon/altitude) and add a module with the sats
     you want (e.g. AMSAT FM birds, NOAA-15/18/19, ISS).
  3. Pass prediction window shows next AOS/LOS with elevation and azimuth.
  4. Tools -> Antenna control / Radio control -> connect to rotctld/rigctld
     on localhost so Gpredict can steer dish and tune for Doppler in real time.
```

## References
- <https://github.com/csete/gpredict>
