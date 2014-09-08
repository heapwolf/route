{
  'includes': [ 'common.gypi' ],
  'targets': [
    {
      'target_name': 'route',
      'product_name': 'route',
      'type': 'static_library',
      'sources': [
       'route.h',
       'route.cc',
      ],
    },
    {
      'target_name': 'test',
      'type': 'executable',
      'sources': [
        'route.cc', 'test.cc',
      ],
      'dependencies': [
        'route'
      ],
    },
  ],
}

