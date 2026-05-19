<!-- generated-from-dump2 -->
# FindMy.py — Apple Find My Network Client

Python library that talks to Apple's FindMy / "Offline Finding" (OF) network — the mesh of every iPhone in the world that anonymously reports BLE beacons from lost AirTags / FindMy-enabled accessories back to iCloud. The library handles the elliptic-curve key derivation (the trick is that an AirTag rotates through a deterministic sequence of public keys derived from a master secret, so given the master you can ask Apple's servers for every report keyed to any of those public keys, then decrypt the GPS payload). Used for both legitimate (own-device tracking without Apple's UI) and research (privacy / anti-stalking) work. Companion to OpenHaystack but in pure Python with async I/O.

```python
import asyncio
from findmy import FindMyAccessory
from findmy.reports.account import AsyncAppleAccount
from findmy.reports.anisette import RemoteAnisetteProvider

async def main():
    anisette = RemoteAnisetteProvider("https://ani.sidestore.io")
    account = AsyncAppleAccount(anisette)
    account.restore(open("account.json").read())  # previously logged-in

    # Load a key file exported from OpenHaystack / Macless-Haystack
    tag = FindMyAccessory.from_plist(open("airtag.plist", "rb"))
    reports = await account.fetch_last_reports(tag)
    for r in sorted(reports, key=lambda r: r.timestamp):
        print(r.timestamp, r.latitude, r.longitude, r.confidence)

asyncio.run(main())
```

## References
- <https://github.com/malmeloo/FindMy.py>
