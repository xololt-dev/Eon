```mermaid
---
title: Game loop
---
stateDiagram-v2
	[*] --> UpdateEntities
	UpdateEntities --> Input
	
	Input --> Physics
	Physics --> Physics: While enough time
	Physics --> Audio
	Audio --> Render
	Render --> Input
	
	Render --> Deinit
	Deinit --> [*]
```