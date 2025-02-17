# Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from ..base.dygraph.base import grad  # noqa: F401
from ..base.dygraph.base import enable_grad  # noqa: F401
from ..base.dygraph.base import no_grad_ as no_grad  # noqa: F401
from ..base.dygraph.base import is_grad_enabled  # noqa: F401
from ..base.dygraph.base import set_grad_enabled  # noqa: F401
from . import backward_mode  # noqa: F401
from .autograd import jacobian, hessian  # noqa: F401
from .backward_mode import backward  # noqa: F401
from .py_layer import PyLayer  # noqa: F401
from .py_layer import PyLayerContext  # noqa: F401
from .saved_tensors_hooks import saved_tensors_hooks
from . import ir_backward

__all__ = [  # noqa
    'jacobian',
    'hessian',
    'backward',
    'PyLayer',
    'PyLayerContext',
    'saved_tensors_hooks',
]
