# VBlank Wait

Wait for the vertical blanking interval with `D3DKMTWaitForVerticalBlankEvent`.

## Snippet
```c
D3DKMT_WAITFORVERTICALBLANKEVENT wait = {};
wait.hAdapter = adapter;
wait.hDevice = device;
wait.VidPnSourceId = sourceId;

NTSTATUS status = D3DKMTWaitForVerticalBlankEvent(&wait);
```

## References
- https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforverticalblankevent
