<!-- generated-from-dump2 -->
# OpenWhip — Claude Code Whip Tray App (joke)

Joke Electron tray app that "whips" Claude (or any agentic coding tool) by simulating Ctrl-C and pasting one of five motivational strings into the active terminal — built to vent frustration at slow tool-using LLMs while still cancelling and re-prompting them with a single click. Runs natively on Windows/macOS via Electron's `globalShortcut` + Node `child_process`; Linux delegates the key injection to `xdotool`. Not technically interesting; cultural artifact of the agentic-coding era worth a look for the input-simulation pattern alone.

```js
// Conceptual: tray click -> SIGINT into focused terminal + paste a string.
const { Tray, globalShortcut, clipboard } = require('electron');
const robot = require('robotjs'); // or xdotool shellout on Linux

tray.on('click', () => {
  // Equivalent of Ctrl-C in the focused terminal.
  robot.keyTap('c', 'control');
  const lines = ["Faster.", "Less talk.", "Cmon.", "...", "..."];
  clipboard.writeText(lines[Math.floor(Math.random() * lines.length)]);
  robot.keyTap('v', 'control'); // paste prompt
  robot.keyTap('enter');
});
```

## References
- <https://github.com/GitFrog1111/OpenWhip>
