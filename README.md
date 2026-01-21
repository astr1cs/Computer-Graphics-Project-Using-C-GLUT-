<h1 align="center">
  🚗 Going Through Places: A Journey by Car
</h1>

<p align="center">
  <strong>A 2D interactive simulation built with C++ and OpenGL</strong><br>
  Showcasing dynamic urban environments, day-night cycles, animated vehicles, and iconic architectural landmarks
</p>

<p align="center">
  <a href="#features">Features</a> •
  <a href="#controls">Controls</a> •
  <a href="#screenshots">Screenshots</a> •
  <a href="#getting-started">Getting Started</a> •
  <a href="#team">Team</a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B" alt="C++">
  <img src="https://img.shields.io/badge/Graphics-OpenGL-5586A4?style=for-the-badge&logo=opengl" alt="OpenGL">
  <img src="https://img.shields.io/badge/Platform-Windows%2011%20%7C%20Ubuntu-0078D6?style=for-the-badge&logo=windows" alt="Platform">
</p>

---

## 🌟 Features

### 🏙️ Scene 1: Urban City View
- **Day/Night Cycle** with moving Sun and Moon
- **Animated Vehicles**: Cargo Truck, Bus, Passenger Car, Metro Train
- **Interactive Controls**: Pause/resume animations, adjust speeds
- **Dynamic Environment**: Floating clouds, garden, skyline buildings

### 🌉 Scene 2: River Bridge Area
- **Two Modes**: Day (river with boats) & Night (bridge with flyover)
- **Vehicles**: Boats, Ambulance, Train, Airplane (night only)
- **Layered Animation**: Independent movement across sky, water, and road layers
- **Speed Controls**: Adjust vehicle speeds in real-time

### 🏙️ Scene 3: Kuala Lumpur City Center (KLCC)
- **Iconic Landmarks**: Petronas Twin Towers, KL Tower, Masjid Jamek
- **Advanced Lighting**: Streetlamps with GL_SPOT directional lighting
- **Special Vehicles**: Tesla Cybertruck, Monorail, Modern Bus
- **Animated Elements**: Water fountains with toggle controls

---

## 🎮 Controls

### Global Controls
| Key | Action |
|-----|---------|
| **V** | Switch to Scene 1 (Urban City) |
| **M** | Switch to Scene 2 (River Bridge) |
| **S** | Switch to Scene 3 (KLCC) |
| **D** | Switch to Day Mode |
| **N** | Switch to Night Mode |
| **Spacebar** | Pause/Resume ALL animations (Scene 1) |

### Scene-Specific Controls
<details>
<summary><b>Scene 1: Urban City</b></summary>

- **Arrow Up/Down**: Train speed
- **Arrow Left/Right**: Sun/Moon speed
- **Page Up/Down**: Cargo Truck speed
- **Left Click**: Pause/resume Train
- **Right Click**: Pause/resume Sun/Moon
- **Middle Click**: Pause/resume Cargo Truck
</details>

<details>
<summary><b>Scene 2: River Bridge</b></summary>

- **Arrow Up/Down**: Red Car speed (Day) / Plane speed (Night)
- **Arrow Left/Right**: Ambulance speed
- **Left Click**: Pause/resume Red Car
- **Right Click**: Pause/resume Night Train
</details>

<details>
<summary><b>Scene 3: KLCC</b></summary>

- **Arrow Up/Down**: Monorail speed
- **Arrow Left/Right**: Sun/Moon speed
- **Page Up/Down**: Cybertruck speed
- **Home/End**: Bus speed
- **L**: Toggle Street Lamps (Night)
- **F**: Toggle Water Fountains
- **Left Click**: Pause/resume Monorail
- **Right Click**: Pause/resume Sun/Moon
</details>

---

## 🛠️ Technical Implementation

### Tech Stack
<p>
  <img src="https://img.shields.io/badge/C++-00599C?style=flat-square&logo=c%2B%2B&logoColor=white" alt="C++">
  <img src="https://img.shields.io/badge/OpenGL-5586A4?style=flat-square&logo=opengl&logoColor=white" alt="OpenGL">
  <img src="https://img.shields.io/badge/GLUT-4B4B4B?style=flat-square" alt="GLUT">
  <img src="https://img.shields.io/badge/CodeBlocks-FF6B35?style=flat-square" alt="CodeBlocks">
</p>

- **Language**: C++
- **Graphics**: OpenGL, GLUT (OpenGL Utility Toolkit)
- **IDE**: CodeBlocks 20.03
- **Platform**: Windows 11 & Ubuntu

### Key Methods
1. **GLUT Functions**: Window management, event handling, timer callbacks
2. **Transform Functions**: `glTranslatef`, `glRotatef`, `glScalef` for object manipulation
3. **Hierarchical Modeling**: Matrix stacks (`glPushMatrix`, `glPopMatrix`) for parent-child relationships
4. **Timer-Based Animation**: `glutTimerFunc` for smooth, frame-independent movement
5. **Conditional Rendering**: Scene and mode switching via boolean flags


---

## 📊 Screenshots

### Scene 1: Urban City
| Day Mode | Night Mode |
|----------|------------|
| <img width="555" height="386" alt="Urban City Day" src="https://github.com/user-attachments/assets/04dfb973-8647-43b7-9ddf-588c92e6be45"> | <img width="544" height="377" alt="Urban City Night" src="https://github.com/user-attachments/assets/583db8e4-c561-48d5-b3f0-aa7ed161a1a8"> |

### Scene 2: Bridge Area
| Day Mode | Night Mode |
|----------|------------|
| <img width="573" height="396" alt="Bridge Day" src="https://github.com/user-attachments/assets/116107f3-295b-4007-ad55-fc9a85a54e24"> | <img width="580" height="407" alt="Bridge Night" src="https://github.com/user-attachments/assets/8a9031dd-a545-4eaf-954d-80307e943136"> |

### Scene 3: KLCC
| Day Mode | Night Mode |
|----------|------------|
| <img width="599" height="418" alt="KLCC Day" src="https://github.com/user-attachments/assets/d3927499-1600-406f-bf6e-dd5556de2257"> | <img width="596" height="412" alt="KLCC Night" src="https://github.com/user-attachments/assets/2794c6ce-1566-4aa7-a043-13f16e0d05a8"> |

---

## 🚀 Getting Started

### Prerequisites
- C++ Compiler (GCC/MinGW)
- OpenGL and GLUT libraries
- CodeBlocks IDE (recommended) or any compatible IDE

### Installation

1. **Clone the repository:**
```bash
git clone https://github.com/astr1cs/Computer-Graphics-Project-Using-C-GLUT-.git
cd Computer-Graphics-Project-Using-C-GLUT-

2. Open the project in CodeBlocks

Ensure OpenGL and GLUT are properly linked in project settings

Build and run the project
Linux Setup
bash
sudo apt-get install freeglut3 freeglut3-dev
g++ main.cpp -o graphics_project -lGL -lGLU -lglut
./graphics_project
Windows Setup
Install CodeBlocks with MinGW

Configure compiler to link against libglut.a or freeglut.lib

Build from the CodeBlocks project file

🧠 Challenges & Solutions
Challenge	Solution
Flickering animations	Enabled double buffering with GLUT_DOUBLE
Inconsistent speed control	Implemented independent global speed variables
Object disappearing off-screen	Added boundary checks and position resets
Scene overlap conflicts	Used boolean flags to isolate scene rendering
Day/Night synchronization	Implemented global isDay flag for all objects
📈 Future Enhancements
Collision Detection: Bounding box implementation for traffic simulation

Audio Integration: Ambient sounds and vehicle effects

Advanced Weather: Dynamic rain, fog, and thunder effects

Texture Mapping: Replace primitives with textured images

Web Porting: Convert to WebGL for browser accessibility

Gamification: Add objectives like "taxi mode" with passenger pickups

👥 Team Members
Member	GitHub	Contribution
Meraz	@astr1cs	Scene 1: Urban City View
Avishek	-	Scene 2: River Bridge Area
Mohaiminul	@MMHT2000	Scene 3: Kuala Lumpur City Center
📝 Academic Information
This project was developed as a Computer Graphics course project, demonstrating:

OpenGL primitive rendering

Hierarchical object modeling

Event-driven programming

Timer-based animation

Interactive user interfaces

Scene management and transitions

📄 License
This project is for educational purposes as part of an academic course. All code and assets are property of the respective team members.

🤝 Contributing
While this is a completed academic project, suggestions and improvements are welcome through issues and pull requests.

📧 Contact
For questions or collaboration opportunities, please open an issue on the GitHub repository.

<div align="center">
⭐ If you find this project interesting, consider giving it a star on GitHub!

https://api.star-history.com/svg?repos=astr1cs/Computer-Graphics-Project-Using-C-GLUT-&type=Date

</div> ```
