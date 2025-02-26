# Gnome Emoji Picker

## Dependencies

```sh
sudo apt update
sudo apt install -y build-essential cmake pkg-config

sudo apt install -y libgtkmm-3.0-dev
sudo apt install -y libkeybinder-3.0-dev
sudo apt install -y libx11-dev
sudo apt install -y libxtst-dev
sudo apt install -y nlohmann-json3-dev
```

## Building From Source

1. Clone the Repository
```sh
git clone https://github.com/shonnoronha/gnome-emoji-picker.git
cd gnome-emoji-picker
```

2. Create a build directory and build the application
```sh
mkdir -p build
cd build
cmake ..
cmake --build .
```

3. Install the Application
```sh
sudo make install
```
This will :
- Install the `emoji_picker` executable to `/usr/local/bin`
- Install emoji data to `/usr/local/share/emoji-picker/`
- Create a desktop entry in `/usr/local/share/applications/`
- Add the application to autostart by creating a symlink in `~/.config/autostart`

## Running the Application
```sh
# Run from the terminal 
# Press Super+. to toggle the window
emoji_picker

# Or Launch directly from your application menu
```





