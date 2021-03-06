cmake_minimum_required( VERSION 2.8 )

project( PerformMultiModalityRegistrationWithMutualInformation )

find_package( ITK REQUIRED )

include( ${ITK_USE_FILE} )
add_executable( PerformMultiModalityRegistrationWithMutualInformation PerformMultiModalityRegistrationWithMutualInformation.cxx )
target_link_libraries( PerformMultiModalityRegistrationWithMutualInformation ${ITK_LIBRARIES} )

install( TARGETS PerformMultiModalityRegistrationWithMutualInformation
  DESTINATION bin/ITKExamples/Registration/Common
  COMPONENT Runtime
  )

install( FILES PerformMultiModalityRegistrationWithMutualInformation.cxx CMakeLists.txt
  DESTINATION share/ITKExamples/Code/Registration/Common/PerformMultiModalityRegistrationWithMutualInformation
  COMPONENT Code
  )

enable_testing()
add_test( NAME PerformMultiModalityRegistrationWithMutualInformationTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/PerformMultiModalityRegistrationWithMutualInformation
  BrainT1SliceBorder20.png
  BrainProtonDensitySliceShifted13x17y.png
  PerformMultiModalityRegistrationWithMutualInformationOutput.png
  PerformMultiModalityRegistrationWithMutualInformationCheckerboardBefore.png
  PerformMultiModalityRegistrationWithMutualInformationCheckerboardAfter.png
  )

