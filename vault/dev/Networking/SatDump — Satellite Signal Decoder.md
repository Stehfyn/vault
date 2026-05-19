<!-- generated-from-dump2 -->
# SatDump — Satellite Signal Decoder

General-purpose satellite signal demodulator/decoder. Takes raw IQ baseband (from an RTL-SDR, Airspy, HackRF, etc.) and decodes a long list of weather and Earth-observation birds: NOAA APT, MetOp HRPT, GOES HRIT/LRIT, Elektro-L, Meteor LRPT, Aqua/Terra X-band. Ships a Qt GUI plus a CLI for headless decoding.

```bash
# Decode a NOAA-19 APT recording.
satdump noaa_apt baseband.wav ./out --samplerate 48000

# Live RTL-SDR pipeline (137 MHz NOAA APT).
satdump live noaa_apt ./out --source rtlsdr --frequency 137912500 \
        --samplerate 1024000 --gain 30 --timeout 900
```

## References
- <https://github.com/SatDump/SatDump>
