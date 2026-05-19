<!-- generated-from-dump2 -->
# IPFS Web UI (Kubo Browser)

React/Redux SPA that ships embedded in `kubo` (the Go IPFS daemon) and in IPFS Desktop, served at `http://127.0.0.1:5001/webui` by the daemon's HTTP API. Lets you browse your local node's pinned objects, drag-and-drop new files (which become content-addressed CIDs), browse the MFS (mutable filesystem), inspect peers and bandwidth, and follow links across the DAG. Worth reading both as a real-world consumer of the IPFS HTTP RPC API (`/api/v0/...`) and as a reference for "what does a content-addressed UX even look like." Talks to kubo via `ipfs-http-client`.

```javascript
// Conceptual usage of the same HTTP API ipfs-webui uses:
import { create } from 'ipfs-http-client'

const ipfs = create({ url: 'http://127.0.0.1:5001/api/v0' })

// Add a file: returns its content-addressed CID
const { cid } = await ipfs.add(Buffer.from('hello'))
console.log(cid.toString()) // QmHash...

// Pin something so it's not GC'd
await ipfs.pin.add(cid)

// Walk a DAG node
for await (const link of ipfs.object.links(cid)) {
  console.log(link.Name, link.Hash.toString())
}
```

## References
- <https://github.com/ipfs/ipfs-webui>
