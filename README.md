# ImGui enum class extension (WIP)

Enable `enum class` types in `ImGui` namespace.  
Please be aware of that this library will directory add enum class definitions and wrappers into `ImGui` namespace.  

You can write like this:
```cpp
ImGui::SetNextWindowSize(ImVec2(700, 600), ImGui::Cond::FirstUseEver);
```

You can also use operators:
```cpp
ImGui::BeginChild(
  "region", ImVec2(0, 0), true,
  ImGui::WindowFlags::NoScrollbar | ImGui::WindowFlags::NoMove);
```

# install 
Copy `imguiEx_EnumClass.hpp` and `#include` it.