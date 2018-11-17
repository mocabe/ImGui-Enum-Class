#pragma once

#include <imgui.h>
#include <type_traits>
#include <utility> // forward

namespace ImGui {

  namespace ec_detail {
    /// create enum class from value
    template <class E>
    constexpr std::underlying_type_t<E> to_underlying_type(E e) {
      return static_cast<std::underlying_type_t<E>>(e);
    }
    /// trait class to use SFINAE on enum class types
    template <class T>
    struct is_enum_flag : std::false_type {};

    /// alias
    template <class T>
    static constexpr bool is_enum_flag_v = is_enum_flag<T>::value;
  } // namespace enum_class_detail

  // operator|
  template <
    class Flag,
    std::enable_if_t<ec_detail::is_enum_flag_v<Flag>, std::nullptr_t> = nullptr>
  constexpr Flag operator|(Flag lhs, Flag rhs) {
    using namespace ec_detail;
    return static_cast<Flag>(to_underlying_type(lhs) | to_underlying_type(rhs));
  }

  // operator|=
  template <
    class Flag,
    std::enable_if_t<ec_detail::is_enum_flag_v<Flag>, std::nullptr_t> = nullptr>
  constexpr Flag& operator|=(Flag& lhs, Flag rhs) {
    lhs = lhs | rhs;
    return lhs;
  }

  // operator&
  template <
    class Flag,
    std::enable_if_t<ec_detail::is_enum_flag_v<Flag>, std::nullptr_t> = nullptr>
  constexpr Flag operator&(Flag lhs, Flag rhs) {
    using namespace ec_detail;
    return static_cast<Flag>(to_underlying_type(lhs) & to_underlying_type(rhs));
  }

  // operator&=
  template <
    class Flag,
    std::enable_if_t<ec_detail::is_enum_flag_v<Flag>, std::nullptr_t> = nullptr>
  constexpr Flag& operator&=(Flag& lhs, Flag rhs) {
    lhs = lhs & rhs;
    return lhs;
  }

  // operator^
  template <
    class Flag,
    std::enable_if_t<ec_detail::is_enum_flag_v<Flag>, std::nullptr_t> = nullptr>
  constexpr Flag operator^(Flag lhs, Flag rhs) {
    using namespace ec_detail;
    return static_cast<Flag>(to_underlying_type(lhs) ^ to_underlying_type(rhs));
  }

  // operator^=
  template <
    class Flag,
    std::enable_if_t<ec_detail::is_enum_flag_v<Flag>, std::nullptr_t> = nullptr>
  constexpr Flag& operator^=(Flag& lhs, Flag rhs) {
    lhs = lhs ^ rhs;
    return lhs;
  }

  // operator~
  template <
    class Flag,
    std::enable_if_t<ec_detail::is_enum_flag_v<Flag>, std::nullptr_t> = nullptr>
  constexpr Flag operator~(Flag flag) {
    using namespace ec_detail;
    return static_cast<Flag>(~(to_underlying_type(flag)));
  }

  // ----------------------------------------
  // Col

  /// ImGuiCol
  enum class Col : int {
    Text                  = ImGuiCol_Text,
    TextDisabled          = ImGuiCol_TextDisabled,
    WindowBg              = ImGuiCol_WindowBg,
    ChildBg               = ImGuiCol_ChildBg,
    PopupBg               = ImGuiCol_PopupBg,
    Border                = ImGuiCol_Border,
    BorderShadow          = ImGuiCol_BorderShadow,
    FrameBg               = ImGuiCol_FrameBg,
    FrameBgHovered        = ImGuiCol_FrameBgHovered,
    FrameBgActive         = ImGuiCol_FrameBgActive,
    TitleBg               = ImGuiCol_TitleBg,
    TitleBgActive         = ImGuiCol_TitleBgActive,
    TitleBgCollapsed      = ImGuiCol_TitleBgCollapsed,
    MenuBarBg             = ImGuiCol_MenuBarBg,
    ScrollbarBg           = ImGuiCol_ScrollbarBg,
    ScrollbarGrab         = ImGuiCol_ScrollbarGrab,
    ScrollbarGrabHovered  = ImGuiCol_ScrollbarGrabHovered,
    ScrollbarGrabActive   = ImGuiCol_ScrollbarGrabActive,
    CheckMark             = ImGuiCol_CheckMark,
    SliderGrab            = ImGuiCol_SliderGrab,
    SliderGrabActive      = ImGuiCol_SliderGrabActive,
    Button                = ImGuiCol_Button,
    ButtonHovered         = ImGuiCol_ButtonHovered,
    ButtonActive          = ImGuiCol_ButtonActive,
    Header                = ImGuiCol_Header,
    HeaderHovered         = ImGuiCol_HeaderHovered,
    HeaderActive          = ImGuiCol_HeaderActive,
    Separator             = ImGuiCol_Separator,
    SeparatorHovered      = ImGuiCol_SeparatorHovered,
    SeparatorActive       = ImGuiCol_SeparatorActive,
    ResizeGrip            = ImGuiCol_ResizeGrip,
    ResizeGripHovered     = ImGuiCol_ResizeGripHovered,
    ResizeGripActive      = ImGuiCol_ResizeGripActive,
    PlotLines             = ImGuiCol_PlotLines,
    PlotLinesHovered      = ImGuiCol_PlotLinesHovered,
    PlotHistogram         = ImGuiCol_PlotHistogram,
    PlotHistogramHovered  = ImGuiCol_PlotHistogramHovered,
    TextSelectedBg        = ImGuiCol_TextSelectedBg,
    DragDropTarget        = ImGuiCol_DragDropTarget,
    NavHighlight          = ImGuiCol_NavHighlight,
    NavWindowingHighlight = ImGuiCol_NavWindowingHighlight,
    NavWindowingDimBg     = ImGuiCol_NavWindowingDimBg,
    ModalWindowDimBg      = ImGuiCol_ModalWindowDimBg,
  };

  inline void PushStyleColor(Col idx, ImU32 col) {
    return PushStyleColor(static_cast<ImGuiCol>(idx), col);
  }
  inline void PushStyleColor(Col idx, const ImVec4& col) {
    return PushStyleColor(static_cast<ImGuiCol>(idx), col);
  }
  inline const ImVec4& GetStyleColorVec4(Col idx) {
    return GetStyleColorVec4(static_cast<ImGuiCol>(idx));
  }
  inline ImU32 GetColorU32(Col idx, float alpha_mul = 1.0f) {
    return GetColorU32(static_cast<ImGuiCol>(idx), alpha_mul);
  }

  // ----------------------------------------
  // Cond

  /// ImGuiCond
  enum class Cond : int {
    Always       = ImGuiCond_Always,
    Once         = ImGuiCond_Once,
    FirstUseEver = ImGuiCond_FirstUseEver,
    Appearing    = ImGuiCond_Appearing,
  };

  inline void SetNextWindowPos(
    const ImVec2& pos, Cond cond, const ImVec2& pivot = ImVec2(0, 0)) {
    return ImGui::SetNextWindowPos(pos, static_cast<ImGuiCond>(cond), pivot);
  }
  inline void SetNextWindowSize(const ImVec2& size, Cond cond) {
    return ImGui::SetNextWindowSize(size, static_cast<ImGuiCond>(cond));
  }
  inline void SetNextWindowCollapsed(bool collapsed, Cond cond) {
    return ImGui::SetNextWindowCollapsed(
      collapsed, static_cast<ImGuiCond>(cond));
  }
  inline void SetWindowPos(const ImVec2& pos, Cond cond) {
    return ImGui::SetWindowPos(pos, static_cast<ImGuiCond>(cond));
  }
  inline void SetWindowSize(const ImVec2& size, Cond cond) {
    return ImGui::SetWindowSize(size, static_cast<ImGuiCond>(cond));
  }
  inline void SetWindowCollapsed(bool collapsed, Cond cond) {
    return ImGui::SetWindowCollapsed(collapsed, static_cast<ImGuiCond>(cond));
  }
  inline void SetWindowPos(const char* name, const ImVec2& pos, Cond cond) {
    return SetWindowPos(name, pos, static_cast<ImGuiCond>(cond));
  }
  inline void SetWindowSize(const char* name, const ImVec2& size, Cond cond) {
    return SetWindowSize(name, size, static_cast<ImGuiCond>(cond));
  }
  inline void SetWindowCollapsed(const char* name, bool collapsed, Cond cond) {
    return SetWindowCollapsed(name, collapsed, static_cast<ImGuiCond>(cond));
  }


  // ----------------------------------------
  // DataType

  /// ImGuiDataType
  enum class DataType : int {
    S32    = ImGuiDataType_S32,
    U32    = ImGuiDataType_U32,
    S64    = ImGuiDataType_S64,
    U64    = ImGuiDataType_U64,
    Float  = ImGuiDataType_Float,
    Double = ImGuiDataType_Double,
  };
  inline bool DragScalar(
    const char* label,
    DataType data_type,
    void* v,
    float v_speed,
    const void* v_min  = NULL,
    const void* v_max  = NULL,
    const char* format = NULL,
    float power        = 1.0f) {
    return ImGui::DragScalar(
      label, static_cast<ImGuiDataType>(data_type), v, v_speed, v_min, v_max,
      format, power);
  }
  inline bool DragScalarN(
    const char* label,
    DataType data_type,
    void* v,
    int components,
    float v_speed,
    const void* v_min  = NULL,
    const void* v_max  = NULL,
    const char* format = NULL,
    float power        = 1.0f) {
    return ImGui::DragScalarN(
      label, static_cast<ImGuiDataType>(data_type), v, components, v_speed,
      v_min, v_max, format, power);
  }
  inline bool SliderScalar(
    const char* label,
    DataType data_type,
    void* v,
    const void* v_min,
    const void* v_max,
    const char* format = NULL,
    float power        = 1.0f) {
    return ImGui::SliderScalar(
      label, static_cast<ImGuiDataType>(data_type), v, v_min, v_max, format,
      power);
  }
  inline bool SliderScalarN(
    const char* label,
    DataType data_type,
    void* v,
    int components,
    const void* v_min,
    const void* v_max,
    const char* format = NULL,
    float power        = 1.0f) {
    return ImGui::SliderScalarN(
      label, static_cast<ImGuiDataType>(data_type), v, components, v_min, v_max,
      format, power);
  }
  inline bool VSliderScalar(
    const char* label,
    const ImVec2& size,
    DataType data_type,
    void* v,
    const void* v_min,
    const void* v_max,
    const char* format = NULL,
    float power        = 1.0f) {
    return ImGui::VSliderScalar(
      label, size, static_cast<ImGuiDataType>(data_type), v, v_min, v_max,
      format, power);
  }

  // ----------------------------------------
  // Dir

  /// ImGuiDir
  enum class Dir : int {
    None  = ImGuiDir_None,
    Left  = ImGuiDir_Left,
    Right = ImGuiDir_Right,
    Up    = ImGuiDir_Up,
    Down  = ImGuiDir_Down,
  };

  inline bool ArrowButton(const char* str_id, Dir dir) {
    return ImGui::ArrowButton(str_id, static_cast<ImGuiDir>(dir));
  }

  // ----------------------------------------
  // Key

  /// ImGuiKey
  enum class Key : int {
    Tab        = ImGuiKey_Tab,
    LeftArrow  = ImGuiKey_LeftArrow,
    RightArrow = ImGuiKey_RightArrow,
    UpArrow    = ImGuiKey_UpArrow,
    DownArrow  = ImGuiKey_DownArrow,
    PageUp     = ImGuiKey_PageUp,
    PageDown   = ImGuiKey_PageDown,
    Home       = ImGuiKey_Home,
    End        = ImGuiKey_End,
    Insert     = ImGuiKey_Insert,
    Delete     = ImGuiKey_Delete,
    Backspace  = ImGuiKey_Backspace,
    Space      = ImGuiKey_Space,
    Enter      = ImGuiKey_Enter,
    Escape     = ImGuiKey_Escape,
    A          = ImGuiKey_A,
    C          = ImGuiKey_C,
    V          = ImGuiKey_V,
    X          = ImGuiKey_X,
    Y          = ImGuiKey_Y,
    Z          = ImGuiKey_Z,
  };

  inline int GetKeyIndex(Key imgui_key) {
    return ImGui::GetKeyIndex(static_cast<ImGuiKey>(imgui_key));
  }

  // ----------------------------------------
  // NavInput

  /// ImGuiNavInput
  enum class NavInput : int {
    // Gamepad Mapping
    Activate    = ImGuiNavInput_Activate,
    Cancel      = ImGuiNavInput_Cancel,
    Input       = ImGuiNavInput_Input,
    Menu        = ImGuiNavInput_Menu,
    DpadLeft    = ImGuiNavInput_DpadLeft,
    DpadRight   = ImGuiNavInput_DpadRight,
    DpadUp      = ImGuiNavInput_DpadUp,
    DpadDown    = ImGuiNavInput_DpadDown,
    LStickLeft  = ImGuiNavInput_LStickLeft,
    LStickRight = ImGuiNavInput_LStickRight,
    LStickUp    = ImGuiNavInput_LStickUp,
    LStickDown  = ImGuiNavInput_LStickDown,
    FocusPrev   = ImGuiNavInput_FocusPrev,
    FocusNext   = ImGuiNavInput_FocusNext,
    TweakSlow   = ImGuiNavInput_TweakSlow,
    TweakFast   = ImGuiNavInput_TweakFast,
  };

  // ----------------------------------------
  // MouseCursor

  /// ImGuiMouseCursor
  enum class MouseCursor : int {
    None       = ImGuiMouseCursor_None,
    Arrow      = ImGuiMouseCursor_Arrow,
    TextInput  = ImGuiMouseCursor_TextInput,
    ResizeAll  = ImGuiMouseCursor_ResizeAll,
    ResizeNS   = ImGuiMouseCursor_ResizeNS,
    ResizeEW   = ImGuiMouseCursor_ResizeEW,
    ResizeNESW = ImGuiMouseCursor_ResizeNESW,
    ResizeNWSE = ImGuiMouseCursor_ResizeNWSE,
    Hand       = ImGuiMouseCursor_Hand,
  };
  inline MouseCursor GetMouseCursor([[maybe_unused]] MouseCursor dummy) {
    return static_cast<MouseCursor>(ImGui::GetMouseCursor());
  }
  inline void SetMouseCursor(MouseCursor type) {
    return ImGui::SetMouseCursor(static_cast<ImGuiMouseCursor>(type));
  }

  // ----------------------------------------
  // StyleVar

  /// ImGuiStyleVar
  enum class StyleVar : int {
    Alpha             = ImGuiStyleVar_Alpha,
    WindowPadding     = ImGuiStyleVar_WindowPadding,
    WindowRounding    = ImGuiStyleVar_WindowRounding,
    WindowBorderSize  = ImGuiStyleVar_WindowBorderSize,
    WindowMinSize     = ImGuiStyleVar_WindowMinSize,
    WindowTitleAlign  = ImGuiStyleVar_WindowTitleAlign,
    ChildRounding     = ImGuiStyleVar_ChildRounding,
    ChildBorderSize   = ImGuiStyleVar_ChildBorderSize,
    PopupRounding     = ImGuiStyleVar_PopupRounding,
    PopupBorderSize   = ImGuiStyleVar_PopupBorderSize,
    FramePadding      = ImGuiStyleVar_FramePadding,
    FrameRounding     = ImGuiStyleVar_FrameRounding,
    FrameBorderSize   = ImGuiStyleVar_FrameBorderSize,
    ItemSpacing       = ImGuiStyleVar_ItemSpacing,
    ItemInnerSpacing  = ImGuiStyleVar_ItemInnerSpacing,
    IndentSpacing     = ImGuiStyleVar_IndentSpacing,
    ScrollbarSize     = ImGuiStyleVar_ScrollbarSize,
    ScrollbarRounding = ImGuiStyleVar_ScrollbarRounding,
    GrabMinSize       = ImGuiStyleVar_GrabMinSize,
    GrabRounding      = ImGuiStyleVar_GrabRounding,
    ButtonTextAlign   = ImGuiStyleVar_ButtonTextAlign,
  };

  inline void PushStyleVar(StyleVar idx, float val) {
    return ImGui::PushStyleVar(static_cast<ImGuiStyleVar>(idx), val);
  }
  inline void PushStyleVar(StyleVar idx, const ImVec2& val) {
    return ImGui::PushStyleVar(static_cast<ImGuiStyleVar>(idx), val);
  }

  // ----------------------------------------
  // DrawCornerFlags

  /// ImDrawCornerFlags
  enum class DrawCornerFlags : int {
    TopLeft  = ImDrawCornerFlags_TopLeft,
    TopRight = ImDrawCornerFlags_TopRight,
    BotLeft  = ImDrawCornerFlags_BotLeft,
    BotRight = ImDrawCornerFlags_BotRight,
    Top      = ImDrawCornerFlags_Top,
    Bot      = ImDrawCornerFlags_Bot,
    Left     = ImDrawCornerFlags_Left,
    Right    = ImDrawCornerFlags_Right,
    All      = ImDrawCornerFlags_All,
  };

  template <>
  struct ec_detail::is_enum_flag<DrawCornerFlags> : std::true_type {};

  inline void AddRect(
    ImDrawList* draw_list,
    const ImVec2& a,
    const ImVec2& b,
    ImU32 col,
    float rounding,
    DrawCornerFlags rounding_corners_flags,
    float thickness = 1.0f) {
    return draw_list->AddRect(
      a, b, col, rounding, static_cast<int>(rounding_corners_flags), thickness);
  }

  inline void AddRectFilled(
    ImDrawList* draw_list,
    const ImVec2& a,
    const ImVec2& b,
    ImU32 col,
    float rounding,
    DrawCornerFlags rounding_corners_flags) {
    return draw_list->AddRectFilled(
      a, b, col, rounding, static_cast<int>(rounding_corners_flags));
  }
  inline void PathRect(
    ImDrawList* draw_list,
    const ImVec2& rect_min,
    const ImVec2& rect_max,
    float rounding,
    DrawCornerFlags rounding_corners_flags) {
    return draw_list->PathRect(
      rect_min, rect_max, rounding, static_cast<int>(rounding_corners_flags));
  }
  inline void AddImageRounded(
    ImDrawList* draw_list,
    ImTextureID user_texture_id,
    const ImVec2& a,
    const ImVec2& b,
    const ImVec2& uv_a,
    const ImVec2& uv_b,
    ImU32 col,
    float rounding,
    DrawCornerFlags rounding_corners) {
    return draw_list->AddImageRounded(
      user_texture_id, a, b, uv_a, uv_b, col, rounding,
      static_cast<int>(rounding_corners));
  }

  // ----------------------------------------
  // DrawListFlags

  /// ImDrawListFlags
  enum class DrawListFlags :int {
    AntiAliasedLines = ImDrawListFlags_AntiAliasedLines,
    AntiAliasedFill  = ImDrawListFlags_AntiAliasedFill,
  };

  template <>
  struct ec_detail::is_enum_flag<DrawListFlags> : std::true_type {};

  // ----------------------------------------
  // FontAtlasFlags

  /// ImFontAtlasFlags
  enum class FontAtlasFlags : int {
    None               = ImFontAtlasFlags_None,
    NoPowerOfTwoHeight = ImFontAtlasFlags_NoPowerOfTwoHeight,
    NoMouseCursors     = ImFontAtlasFlags_NoMouseCursors,
  };

  template <>
  struct ec_detail::is_enum_flag<FontAtlasFlags> : std::true_type {};

  // ----------------------------------------
  // BackendFlags

  /// ImGuiBackendFlags
  enum class BackendFlags {
    HasGamepad      = ImGuiBackendFlags_HasGamepad,
    HasMouseCursors = ImGuiBackendFlags_HasMouseCursors,
    HasSetMousePos  = ImGuiBackendFlags_HasSetMousePos,
  };

  template <>
  struct ec_detail::is_enum_flag<BackendFlags> : std::true_type {};

  // ----------------------------------------
  // ColorEditorFlags

  /// ImGuiColorEditFlags
  enum class ColorEditFlags : int {
    None           = ImGuiColorEditFlags_None,
    NoAlpha        = ImGuiColorEditFlags_NoAlpha,
    NoPicker       = ImGuiColorEditFlags_NoPicker,
    NoOptions      = ImGuiColorEditFlags_NoOptions,
    NoSmallPreview = ImGuiColorEditFlags_NoSmallPreview,
    NoInputs       = ImGuiColorEditFlags_NoInputs,
    NoTooltip      = ImGuiColorEditFlags_NoTooltip,
    NoLabel        = ImGuiColorEditFlags_NoLabel,
    NoSidePreview  = ImGuiColorEditFlags_NoSidePreview,
    NoDragDrop     = ImGuiColorEditFlags_NoDragDrop,

    AlphaBar         = ImGuiColorEditFlags_AlphaBar,
    AlphaPreview     = ImGuiColorEditFlags_AlphaPreview,
    AlphaPreviewHalf = ImGuiColorEditFlags_AlphaPreviewHalf,
    HDR              = ImGuiColorEditFlags_HDR,
    RGB              = ImGuiColorEditFlags_RGB,
    HSV              = ImGuiColorEditFlags_HSV,
    HEX              = ImGuiColorEditFlags_HEX,
    Uint8            = ImGuiColorEditFlags_Uint8,
    Float            = ImGuiColorEditFlags_Float,
    PickerHueBar     = ImGuiColorEditFlags_PickerHueBar,
    PickerHueWheel   = ImGuiColorEditFlags_PickerHueWheel,
  };

  template <>
  struct ec_detail::is_enum_flag<ColorEditFlags> : std::true_type {};

  inline bool ColorEdit3(
    const char* label, float col[3], ColorEditFlags flags) {
    return ImGui::ColorEdit3(
      label, col, static_cast<ImGuiColorEditFlags>(flags));
  }
  inline bool ColorEdit4(
    const char* label, float col[4], ColorEditFlags flags) {
    return ImGui::ColorEdit4(
      label, col, static_cast<ImGuiColorEditFlags>(flags));
  }
  inline bool ColorPicker3(
    const char* label, float col[3], ColorEditFlags flags) {
    return ImGui::ColorPicker3(
      label, col, static_cast<ImGuiColorEditFlags>(flags));
  }
  inline bool ColorPicker4(
    const char* label,
    float col[4],
    ColorEditFlags flags,
    const float* ref_col = NULL) {
    return ImGui::ColorPicker4(
      label, col, static_cast<ImGuiColorEditFlags>(flags), ref_col);
  }
  inline bool ColorButton(
    const char* desc_id,
    const ImVec4& col,
    ColorEditFlags flags,
    ImVec2 size = ImVec2(0, 0)) {
    return ImGui::ColorButton(
      desc_id, col, static_cast<ImGuiColorEditFlags>(flags), size);
  }
  inline void SetColorEditOptions(ColorEditFlags flags) {
    return ImGui::SetColorEditOptions(static_cast<ImGuiColorEditFlags>(flags));
  }

  // ----------------------------------------
  // ColumnsFlags

  /// ImGuiColumnsFlags
  enum class ColumnsFlags {
    // empty?
  };

  template <>
  struct ec_detail::is_enum_flag<ColumnsFlags> : std::true_type {};

  // ----------------------------------------
  // ConfigFlags

  /// ImGuiConfigFlags
  enum class ConfigFlags : int {
    NavEnableKeyboard    = ImGuiConfigFlags_NavEnableKeyboard,
    NavEnableGamepad     = ImGuiConfigFlags_NavEnableGamepad,
    NavEnableSetMousePos = ImGuiConfigFlags_NavEnableSetMousePos,
    NavNoCaptureKeyboard = ImGuiConfigFlags_NavNoCaptureKeyboard,
    NoMouse              = ImGuiConfigFlags_NoMouse,
    NoMouseCursorChange  = ImGuiConfigFlags_NoMouseCursorChange,

    IsSRGB        = ImGuiConfigFlags_IsSRGB,
    IsTouchScreen = ImGuiConfigFlags_IsTouchScreen,
  };

  template <>
  struct ec_detail::is_enum_flag<ConfigFlags> : std::true_type {};

  // ----------------------------------------
  // ComboFlags

  /// ImGuiComboFlags
  enum class ComboFlags {
    None           = ImGuiComboFlags_None,
    PopupAlignLeft = ImGuiComboFlags_PopupAlignLeft,
    HeightSmall    = ImGuiComboFlags_HeightSmall,
    HeightRegular  = ImGuiComboFlags_HeightRegular,
    HeightLarge    = ImGuiComboFlags_HeightLarge,
    HeightLargest  = ImGuiComboFlags_HeightLargest,
    NoArrowButton  = ImGuiComboFlags_NoArrowButton,
    NoPreview      = ImGuiComboFlags_NoPreview,
    HeightMask_    = ImGuiComboFlags_HeightMask_, 
  };

  template <>
  struct ec_detail::is_enum_flag<ComboFlags> : std::true_type {};

  inline bool BeginCombo(
    const char* label, const char* preview_value, ComboFlags flags) {
    return ImGui::BeginCombo(
      label, preview_value, static_cast<ImGuiComboFlags>(flags));
  }

  // ----------------------------------------
  // DragDropFlags

  /// ImGuiDragDropFlags
  enum class DragDropFlags {
    // clang-format off
    ImGuiDragDropFlags_None                     = ImGuiDragDropFlags_None,
    // BeginDragDropSource() flags,
    ImGuiDragDropFlags_SourceNoPreviewTooltip   = ImGuiDragDropFlags_SourceNoPreviewTooltip,
    ImGuiDragDropFlags_SourceNoDisableHover     = ImGuiDragDropFlags_SourceNoDisableHover,
    ImGuiDragDropFlags_SourceNoHoldToOpenOthers = ImGuiDragDropFlags_SourceNoHoldToOpenOthers,
    ImGuiDragDropFlags_SourceAllowNullID        = ImGuiDragDropFlags_SourceAllowNullID,
    ImGuiDragDropFlags_SourceExtern             = ImGuiDragDropFlags_SourceExtern,
    ImGuiDragDropFlags_SourceAutoExpirePayload  = ImGuiDragDropFlags_SourceAutoExpirePayload,
     // AcceptDragDropPayload() flags,
    ImGuiDragDropFlags_AcceptBeforeDelivery     = ImGuiDragDropFlags_AcceptBeforeDelivery,
    ImGuiDragDropFlags_AcceptNoDrawDefaultRect  = ImGuiDragDropFlags_AcceptNoDrawDefaultRect,
    ImGuiDragDropFlags_AcceptNoPreviewTooltip   = ImGuiDragDropFlags_AcceptNoPreviewTooltip,
    ImGuiDragDropFlags_AcceptPeekOnly           = ImGuiDragDropFlags_AcceptPeekOnly,
    // clang-format on
  };

  template <>
  struct ec_detail::is_enum_flag<DragDropFlags> : std::true_type {};

  inline bool BeginDragDropSource(DragDropFlags flags) {
    return ImGui::BeginDragDropSource(static_cast<ImGuiDragDropFlags>(flags));
  }
  inline const ImGuiPayload* AcceptDragDropPayload(
    const char* type, DragDropFlags flags) {
    return ImGui::AcceptDragDropPayload(
      type, static_cast<ImGuiDragDropFlags>(flags));
  }

  // ----------------------------------------
  // FocusedFlags

  /// ImGuiFocusedFlags
  enum class FocusedFlags {
    None                = ImGuiFocusedFlags_None,
    ChildWindows        = ImGuiFocusedFlags_ChildWindows,
    RootWindow          = ImGuiFocusedFlags_RootWindow,
    AnyWindow           = ImGuiFocusedFlags_AnyWindow,
    RootAndChildWindows = ImGuiFocusedFlags_RootAndChildWindows,
  };

  template <>
  struct ec_detail::is_enum_flag<FocusedFlags> : std::true_type {};

  inline bool IsWindowFocused(FocusedFlags flags) {
    return ImGui::IsWindowFocused(static_cast<ImGuiFocusedFlags>(flags));
  }

  // ----------------------------------------
  // HoverredFlags

  /// ImGuiHoverredFlags
  enum class HoveredFlags {
  // clang-format off
    None                         = ImGuiHoveredFlags_None,
    ChildWindows                 = ImGuiHoveredFlags_ChildWindows,
    RootWindow                   = ImGuiHoveredFlags_RootWindow,
    AnyWindow                    = ImGuiHoveredFlags_AnyWindow,
    AllowWhenBlockedByPopup      = ImGuiHoveredFlags_AllowWhenBlockedByPopup,
    // AllowWhenBlockedByModel      = ImGuiHoveredFlags_AllowWhenBlockedByModal,
    AllowWhenBlockedByActiveItem = ImGuiHoveredFlags_AllowWhenBlockedByActiveItem,
    AllowWhenOverlapped          = ImGuiHoveredFlags_AllowWhenOverlapped,
    AllowWhenDisabled            = ImGuiHoveredFlags_AllowWhenDisabled,
    RectOnly                     = ImGuiHoveredFlags_RectOnly,
    RootAndChildWindows          = ImGuiHoveredFlags_RootAndChildWindows,
  // clang-format on
  };

  template <>
  struct ec_detail::is_enum_flag<HoveredFlags> : std::true_type {};

  inline bool IsWindowHovered(HoveredFlags flags) {
    return ImGui::IsWindowHovered(static_cast<ImGuiHoveredFlags>(flags));
  }
  inline bool IsItemHovered(HoveredFlags flags) {
    return ImGui::IsItemHovered(static_cast<ImGuiHoveredFlags>(flags));
  }

  // ----------------------------------------
  // InputTextFlags

  /// ImGuiInputTextFlags
  enum class InputTextFlags : int {
    None                = ImGuiInputTextFlags_None,
    CharsDecimal        = ImGuiInputTextFlags_CharsDecimal,
    CharsHexadecimal    = ImGuiInputTextFlags_CharsHexadecimal,
    CharsUppercase      = ImGuiInputTextFlags_CharsUppercase,
    CharsNoBlank        = ImGuiInputTextFlags_CharsNoBlank,
    AutoSelectAll       = ImGuiInputTextFlags_AutoSelectAll,
    EnterReturnsTure    = ImGuiInputTextFlags_EnterReturnsTrue,
    CallbackCompletion  = ImGuiInputTextFlags_CallbackCompletion,
    CallbackHistory     = ImGuiInputTextFlags_CallbackHistory,
    CallbackAlways      = ImGuiInputTextFlags_CallbackAlways,
    CallbackCharFilter  = ImGuiInputTextFlags_CallbackCharFilter,
    AllowTabInput       = ImGuiInputTextFlags_AllowTabInput,
    CtrlEnterForNewLine = ImGuiInputTextFlags_CtrlEnterForNewLine,
    NoHorizontalScroll  = ImGuiInputTextFlags_NoHorizontalScroll,
    AlwaysInsertMode    = ImGuiInputTextFlags_AlwaysInsertMode,
    ReadOnly            = ImGuiInputTextFlags_ReadOnly,
    Password            = ImGuiInputTextFlags_Password,
    NoUndoRedo          = ImGuiInputTextFlags_NoUndoRedo,
    CharsScientific     = ImGuiInputTextFlags_CharsScientific,
    CallbackResize      = ImGuiInputTextFlags_CallbackResize,
  };

  template <>
  struct ec_detail::is_enum_flag<InputTextFlags> : std::true_type {};

  inline bool InputText(
    const char* label,
    char* buf,
    size_t buf_size,
    InputTextFlags flags,
    ImGuiInputTextCallback callback = NULL,
    void* user_data                 = NULL) {
    return ImGui::InputText(
      label, buf, buf_size, static_cast<ImGuiInputTextFlags>(flags), callback,
      user_data);
  }

  inline bool InputTextMultiline(
    const char* label,
    char* buf,
    size_t buf_size,
    const ImVec2& size,
    InputTextFlags flags,
    ImGuiInputTextCallback callback = NULL,
    void* user_data                 = NULL) {
    return ImGui::InputTextMultiline(
      label, buf, buf_size, size, static_cast<ImGuiInputTextFlags>(flags),
      callback, user_data);
  }

  inline bool InputFloat(
    const char* label,
    float* v,
    float step,
    float step_fast,
    const char* format,
    InputTextFlags extra_flags) {
    return ImGui::InputFloat(
      label, v, step, step_fast, format,
      static_cast<ImGuiInputTextFlags>(extra_flags));
  }

  inline bool InputFloat2(
    const char* label,
    float v[2],
    const char* format,
    InputTextFlags extra_flags) {
    return ImGui::InputFloat2(
      label, v, format, static_cast<ImGuiInputTextFlags>(extra_flags));
  }

  inline bool InputFloat3(
    const char* label,
    float v[3],
    const char* format,
    InputTextFlags extra_flags) {
    return ImGui::InputFloat3(
      label, v, format, static_cast<ImGuiInputTextFlags>(extra_flags));
  }

  inline bool InputFloat4(
    const char* label,
    float v[4],
    const char* format,
    InputTextFlags extra_flags) {
    return ImGui::InputFloat4(
      label, v, format, static_cast<ImGuiInputTextFlags>(extra_flags));
  }

  inline bool InputInt(
    const char* label,
    int* v,
    int step,
    int step_fast,
    InputTextFlags extra_flags) {
    return ImGui::InputInt(
      label, v, step, step_fast, static_cast<ImGuiInputTextFlags>(extra_flags));
  }

  inline bool InputInt2(
    const char* label, int v[2], InputTextFlags extra_flags) {
    return ImGui::InputInt2(
      label, v, static_cast<ImGuiInputTextFlags>(extra_flags));
  }

  inline bool InputInt3(
    const char* label, int v[3], InputTextFlags extra_flags) {
    return ImGui::InputInt3(
      label, v, static_cast<ImGuiInputTextFlags>(extra_flags));
  }

  inline bool InputInt4(
    const char* label, int v[4], InputTextFlags extra_flags) {
    return ImGui::InputInt4(
      label, v, static_cast<ImGuiInputTextFlags>(extra_flags));
  }

  inline bool InputDouble(
    const char* label,
    double* v,
    double step,
    double step_fast,
    const char* format,
    InputTextFlags extra_flags) {
    return ImGui::InputDouble(
      label, v, step, step_fast, format,
      static_cast<ImGuiInputTextFlags>(extra_flags));
  }

  inline bool InputScalar(
    const char* label,
    DataType data_type,
    void* v,
    const void* step,
    const void* step_fast,
    const char* format,
    InputTextFlags extra_flags) {
    return ImGui::InputScalar(
      label, static_cast<ImGuiDataType>(data_type), v, step, step_fast, format,
      static_cast<ImGuiInputTextFlags>(extra_flags));
  }
  inline bool InputScalarN(
    const char* label,
    DataType data_type,
    void* v,
    int components,
    const void* step,
    const void* step_fast,
    const char* format,
    InputTextFlags extra_flags) {
    return ImGui::InputScalarN(
      label, static_cast<ImGuiDataType>(data_type), v, components, step,
      step_fast, format, static_cast<ImGuiInputTextFlags>(extra_flags));
  }

  // ----------------------------------------
  // SelectableFlags

  /// ImGuiSelectableFlags
  enum class SelectableFlags {
    None             = ImGuiSelectableFlags_None,
    DontClosePopups  = ImGuiSelectableFlags_DontClosePopups,
    SpanAllColumns   = ImGuiSelectableFlags_SpanAllColumns,
    AllowDoubleClick = ImGuiSelectableFlags_AllowDoubleClick,
    Disabled         = ImGuiSelectableFlags_Disabled,
  };

  template <>
  struct ec_detail::is_enum_flag<SelectableFlags> : std::true_type {};

  inline bool Selectable(
    const char* label,
    bool selected,
    SelectableFlags flags,
    const ImVec2& size = ImVec2(0, 0)) {
    return ImGui::Selectable(
      label, selected, static_cast<ImGuiSelectableFlags>(flags), size);
  }
  inline bool Selectable(
    const char* label,
    bool* p_selected,
    SelectableFlags flags,
    const ImVec2& size = ImVec2(0, 0)) {
    return ImGui::Selectable(
      label, p_selected, static_cast<ImGuiSelectableFlags>(flags), size);
  }

  // ----------------------------------------
  // TreeNodeFlags

  /// ImGuiTreeNodeFlags
  enum class TreeNodeFlags : int {
    None              = ImGuiTreeNodeFlags_None,
    Selected          = ImGuiTreeNodeFlags_Selected,
    Framed            = ImGuiTreeNodeFlags_Framed,
    AllowItemOverlap  = ImGuiTreeNodeFlags_AllowItemOverlap,
    NoTreePushOnOpen  = ImGuiTreeNodeFlags_NoTreePushOnOpen,
    NoAutoOpenOnLog   = ImGuiTreeNodeFlags_NoAutoOpenOnLog,
    DefaultOpen       = ImGuiTreeNodeFlags_DefaultOpen,
    OpenOnDoubleClick = ImGuiTreeNodeFlags_OpenOnDoubleClick,
    OpenOnArrow       = ImGuiTreeNodeFlags_OpenOnArrow,
    Leaf              = ImGuiTreeNodeFlags_Leaf,
    Bullet            = ImGuiTreeNodeFlags_Bullet,
    FramePadding      = ImGuiTreeNodeFlags_FramePadding,
    // SpanAllAvailWidth    = ImGuITreeNodeFlags_SpanAllAvailWidth,
    // NoScrollOnOpen       = ImGuiTreeNodeFlags_NoScrollOnOpen,
    NavLeftJumpsBackHere = ImGuiTreeNodeFlags_NavLeftJumpsBackHere,
    CollapsingHeader     = ImGuiTreeNodeFlags_CollapsingHeader,
  };

  template <>
  struct ec_detail::is_enum_flag<TreeNodeFlags> : std::true_type {};

  inline bool TreeNodeEx(const char* label, TreeNodeFlags flags) {
    return ImGui::TreeNodeEx(label, static_cast<ImGuiTreeNodeFlags>(flags));
  }

  template <class... Args>
  inline bool TreeNodeEx(
    const char* str_id, TreeNodeFlags flags, const char* fmt, Args&&... args) {
    return ImGui::TreeNodeEx(
      str_id, static_cast<ImGuiTreeNodeFlags>(flags), fmt,
      std::forward<Args>(args)...);
  }
  template <class... Args>
  inline bool TreeNodeEx(
    const void* ptr_id, TreeNodeFlags flags, const char* fmt, Args&&... args) {
    return ImGui::TreeNodeEx(
      ptr_id, static_cast<ImGuiTreeNodeFlags>(flags), fmt,
      std::forward<Args>(args)...);
  }
  inline bool TreeNodeExV(
    const char* str_id, TreeNodeFlags flags, const char* fmt, va_list args) {
    return ImGui::TreeNodeExV(
      str_id, static_cast<ImGuiTreeNodeFlags>(flags), fmt, args);
  }
  inline bool TreeNodeExV(
    const void* ptr_id, TreeNodeFlags flags, const char* fmt, va_list args) {
    return ImGui::TreeNodeExV(
      ptr_id, static_cast<ImGuiTreeNodeFlags>(flags), fmt, args);
  }
  inline bool CollapsingHeader(const char* label, TreeNodeFlags flags) {
    return ImGui::CollapsingHeader(
      label, static_cast<ImGuiTreeNodeFlags>(flags));
  }
  inline bool CollapsingHeader(
    const char* label, bool* p_open, TreeNodeFlags flags) {
    return CollapsingHeader(
      label, p_open, static_cast<ImGuiTreeNodeFlags>(flags));
  }

  // ----------------------------------------
  // WindowFlags

  /// ImGuiWindowFlags
  enum class WindowFlags : int {
    None                      = ImGuiWindowFlags_None,
    NoTitleBar                = ImGuiWindowFlags_NoTitleBar,
    NoResize                  = ImGuiWindowFlags_NoResize,
    NoMove                    = ImGuiWindowFlags_NoMove,
    NoScrollbar               = ImGuiWindowFlags_NoScrollbar,
    NoScrollWithMouse         = ImGuiWindowFlags_NoScrollWithMouse,
    NoCollapse                = ImGuiWindowFlags_NoCollapse,
    AlwaysAutoReize           = ImGuiWindowFlags_AlwaysAutoResize,
    NoBackground              = ImGuiWindowFlags_NoBackground,
    NoSavedSettings           = ImGuiWindowFlags_NoSavedSettings,
    NoMouseInputs             = ImGuiWindowFlags_NoMouseInputs,
    MenuBar                   = ImGuiWindowFlags_MenuBar,
    HorizontalScrollbar       = ImGuiWindowFlags_HorizontalScrollbar,
    NoFocusOnAppearing        = ImGuiWindowFlags_NoFocusOnAppearing,
    NoBringToFrontOnFocus     = ImGuiWindowFlags_NoBringToFrontOnFocus,
    AlwaysVerticalScrollbar   = ImGuiWindowFlags_AlwaysVerticalScrollbar,
    AlwaysHorizontalScrollbar = ImGuiWindowFlags_AlwaysHorizontalScrollbar,
    AlwaysUseWindowPadding    = ImGuiWindowFlags_AlwaysUseWindowPadding,
    NoNavInputs               = ImGuiWindowFlags_NoNavInputs,
    NoNavFocus                = ImGuiWindowFlags_NoNavFocus,
    NoNav                     = ImGuiWindowFlags_NoNav,
    NoDecoration              = ImGuiWindowFlags_NoDecoration,
    NoInputs                  = ImGuiWindowFlags_NoInputs,
  };

  template <>
  struct ec_detail::is_enum_flag<WindowFlags> : std::true_type {};

  inline bool Begin(const char* name, bool* p_open, WindowFlags flags) {
    return Begin(name, p_open, static_cast<ImGuiWindowFlags>(flags));
  }
  inline bool BeginChild(
    const char* str_id, const ImVec2& size, bool border, WindowFlags flags) {
    return ImGui::BeginChild(
      str_id, size, border, static_cast<ImGuiWindowFlags>(flags));
  }
  inline bool BeginChild(
    ImGuiID id, const ImVec2& size, bool border, WindowFlags flags) {
    return ImGui::BeginChild(
      id, size, border, static_cast<ImGuiWindowFlags>(flags));
  }
  inline bool BeginPopup(const char* str_id, WindowFlags flags) {
    return ImGui::BeginPopup(str_id, static_cast<ImGuiWindowFlags>(flags));
  }
  inline bool BeginPopupModal(
    const char* name, bool* p_open, WindowFlags flags) {
    return ImGui::BeginPopupModal(
      name, p_open, static_cast<ImGuiWindowFlags>(flags));
  }
  inline bool BeginChildFrame(
    ImGuiID id, const ImVec2& size, WindowFlags flags) {
    return ImGui::BeginChild(id, size, static_cast<ImGuiWindowFlags>(flags));
  }

} // namespace ImGui
