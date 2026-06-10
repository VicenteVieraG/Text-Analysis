add_library(report STATIC report.cpp)

target_link_libraries(report
    PRIVATE inja
)