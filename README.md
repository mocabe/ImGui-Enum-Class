# ImGui enum class extension

Enable `enum class` types in `ImGui` namespace.  
Please be aware of that this library will directly add enum class definitions and wrappers into `ImGui` namespace.  

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
Copy `imgui_EnumClass.hpp` into your include directory and `#include` it.

or use `CMake`
```cmake
add_subdirectory(path-to-this-library)

# use imgui_EnumClass to add include directory
target_link_libraries(
  your-target
  imgui_EnumClass
  other-libs
)
```