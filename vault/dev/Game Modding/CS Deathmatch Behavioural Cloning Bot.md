<!-- generated-from-dump2 -->
# CS Deathmatch Behavioural Cloning Bot

Code + dataset for Tim Pearce et al.'s paper "Counter-Strike Deathmatch with Large-Scale Behavioural Cloning" (IEEE CoG / NeurIPS workshop). Trains a CNN+LSTM policy on ~70 hours of human deathmatch gameplay scraped from Twitch — input is raw 280x150 RGB frames, output is keyboard + mouse-delta actions. Notable because it shows you can get a competitive bot from pure imitation learning on a 3D shooter without engine-side access (no game state, only pixels + key logs).

```python
import torch, torch.nn as nn

class CSGOPolicy(nn.Module):
    def __init__(self):
        super().__init__()
        self.cnn = nn.Sequential(  # ~Atari-DQN style stack
            nn.Conv2d(3, 32, 8, 4), nn.ReLU(),
            nn.Conv2d(32, 64, 4, 2), nn.ReLU(),
            nn.Conv2d(64, 64, 3, 1), nn.ReLU(),
            nn.Flatten(),
        )
        self.lstm = nn.LSTM(input_size=64 * 7 * 7, hidden_size=512)
        self.keys  = nn.Linear(512, 11)  # WASD + crouch + jump + ...
        self.mouse = nn.Linear(512, 2)   # dx, dy
```

## References
- <https://github.com/TeaPearce/Counter-Strike_Behavioural_Cloning>
