<!-- generated-from-dump2 -->
# WindTerm — Cross-Platform SSH and Serial Terminal

Cross-platform terminal client that competes with MobaXterm/SecureCRT/Tabby in the "all the connection types in one window" niche: SSH (with OpenSSH-compatible key handling, jump hosts, X11 forwarding), SFTP browser side-by-side with the shell, serial (real COM ports + USB-serial), Telnet, raw socket, plus a Tmux *control mode* integration that turns remote tmux sessions into native local tabs. The two distinguishing features vs. competitors: (1) very fast text rendering — claims 30+ GB/s scrollback throughput with hardware-accelerated text; (2) sftp panel auto-syncs with the working directory of the active shell (cd in shell, sftp pane follows). Closed-source binary but free for personal use; not open-source despite the GitHub presence.

```text
# Notable capabilities worth knowing exist:
#   - Jump host chains:  edit session > Proxy Server > SSH bastion.example.com
#   - tmux control mode:  prefix + : control-mode  -> WindTerm renders each tmux
#       window as a native local tab/pane (no escape-sequence scrollback loss).
#   - Serial: file > new session > Serial; auto-enumerates COM ports.
#   - SFTP/SCP/Zmodem are all built-in; rz/sz works out of the box.
```

## References
- <https://github.com/kingToolbox/WindTerm>
